export const fetchMarkdownPosts = async () => {
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
export const fetchPostCategories = async () => {
  const allPostFiles = import.meta.glob('/src/routes/blog/*.md');
  const iterablePostFiles = Object.entries(allPostFiles);
  const categories: string[] = [];
  await Promise.all(
    iterablePostFiles.map(async ([_, resolver]) => {
      const { metadata } = await resolver();
      for (const category of metadata.category) {
        if (categories.indexOf(category) === -1) {
          categories.push(category);
        }
      }
    })
  );

  return categories;
};

