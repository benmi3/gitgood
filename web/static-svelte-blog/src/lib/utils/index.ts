export const fetchAllPosts = async () => {
  const allPostFiles = import.meta.glob('/src/routes/blog/*.md');
  const iterablePostFiles = Object.entries(allPostFiles);
  const allPosts = await Promise.all(
    iterablePostFiles.map(async ([path, resolver]) => {
      const { metadata } = await resolver();
      const postPath = path.slice(11, -3);

      return {
        meta: metadata,
        path: postPath
      };
    })
  );

  return allPosts;
};
export const fetchPostsFilters = async (filter: string) => {
  const allPostFiles = import.meta.glob('/src/routes/blog/*.md');
  const iterablePostFiles = Object.entries(allPostFiles);
  const filterArr: string[] = [];
  await Promise.all(
    iterablePostFiles.map(async ([path, resolver]) => {
      const { metadata } = await resolver();
      if (metadata[filter] != undefined) {
        if (Array.isArray(metadata[filter])) {
          for (const item of metadata[filter]) {
            if (filterArr.indexOf(item) === -1) {
              filterArr.push(item);
            }
          }
        } else {
          filterArr.push(metadata[filter]);
        }
      }
    })
  );

  return filterArr;
};

export const fetchPostsFiltered = async (filter: string, value: string) => {
  const allPostFiles = import.meta.glob('/src/routes/blog/*.md');
  const iterablePostFiles = Object.entries(allPostFiles);

  const allPosts = await Promise.all(
    iterablePostFiles.map(async ([path, resolver]) => {
      const { metadata } = await resolver();
      const postPath = path.slice(11, -3);
      let itemcheck = 0;
      if (metadata[filter] != undefined) {
        switch (Array.isArray(metadata[filter])) {
          case true:
            for (const item of metadata[filter]) {
              if (item === value) {
                itemcheck++;
                break;
              }
            }
            break;
          case false:
            if (metadata[filter] === value) {
              itemcheck++;
            }
            break;
        }
        if (itemcheck === 0) {
          return;
        }
        return {
          meta: metadata,
          path: postPath
        };
      }
    })
  );

  return allPosts;
};

