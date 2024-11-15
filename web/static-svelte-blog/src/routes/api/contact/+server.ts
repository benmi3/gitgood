import { fetchAllLinks } from '$lib/utils';
import { json } from '@sveltejs/kit';

export const GET = async () => {
  const allLinks = await fetchAllLinks();
  return json(allLinks[0]);
};

