import { fetchPostsFilters } from '$lib/utils';
import { json } from '@sveltejs/kit';

export const GET = async ({ params }) => {
  const filteredPosts = await fetchPostsFilters(params.filter);

  return json(filteredPosts);
};
