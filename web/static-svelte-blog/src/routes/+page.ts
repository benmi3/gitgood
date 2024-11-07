export const load = async ({ fetch }) => {
  const response = await fetch(`/api/post`);
  const post = await response.json();

  return {
    post
  };
};
