import { error } from '@sveltejs/kit';
import type { PageLoad } from './$types';

export const load: PageLoad = async ({ fetch }) => {
  // let offset: number = parseInt(params.url.searchParams.get('offset'));
  // if (isNaN(offset)) {
  //   offset = 0;
  // }
  // TODO: add paging
  const response = await fetch(`/api/posts`);
  const posts = await response.json();
  if (posts) {
    return {
      posts
    };
  }
  error(404, 'Not found');
};

