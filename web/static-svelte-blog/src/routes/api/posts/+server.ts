import { fetchAllPosts } from '$lib/utils';
import { json } from '@sveltejs/kit';

export const GET = async (params) => {
  let pagenum: number = parseInt(params.url.searchParams.get('page'));
  if (isNaN(pagenum)) {
    pagenum = 0;
  }
  const allPosts = await fetchAllPosts(pagenum);
  const sortedPosts = allPosts.sort((a, b) => {
    return new Date(b.meta.date) - new Date(a.meta.date);
  });

  return json(sortedPosts);
};

