import { fetchPostCategories } from '$lib/utils';
import { json } from '@sveltejs/kit';

export const GET = async () => {
  const allCategories = await fetchPostCategories();

  const sortedCategories = allCategories.sort();
  return json(sortedCategories);
};
