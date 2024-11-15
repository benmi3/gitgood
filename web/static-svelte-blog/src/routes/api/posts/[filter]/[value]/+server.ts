import { fetchPostsFiltered } from '$lib/utils';
import { json } from '@sveltejs/kit';

export const GET = async ({ params }) => {
  const filteredPosts = await fetchPostsFiltered(params.filter, params.value);

  return json(filteredPosts);
};
