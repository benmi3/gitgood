export const load = async ({ fetch }) => {
  const response = await fetch(`/api/posts?limit=1`);
  const res = await response.json();

  return {
    post: res[0].meta,
    path: res[0].path,
    total: res[0].total,
  };
};

