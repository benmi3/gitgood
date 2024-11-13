import { fetchAllPosts } from '$lib/utils';
import { json } from '@sveltejs/kit';

export const GET = async (params) => {
  let offsetParam: string | null = params.url.searchParams.get('offset')
  let offset: number = offsetParam != null ? parseInt(offsetParam) : 0;
  if (isNaN(offset)) {
    offset = 0;
  }
  let limitParam = params.url.searchParams.get('limit')
  let limit: number = limitParam != null ? parseInt(limitParam) : 0;
  if (isNaN(limit)) {
    limit = 0;
  }

  const allPosts = await fetchAllPosts(offset, limit);


  return json(allPosts);
};

