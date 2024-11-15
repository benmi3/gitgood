<script lang="ts">
	import type { PageData } from './$types';

	let { data }: { data: PageData } = $props();
	let posts = $state(data.posts);
	let displayMore = $state(posts[0].total != posts.length);

	async function getMorePosts() {
		const response = await fetch(`/api/posts?offset=` + posts.length.toString());
		const newposts = await response.json();
		if (posts) {
			for (const post of newposts) {
				posts.push(post);
			}
			displayMore = posts[0].total != posts.length;
			return;
		}
		return;
	}
</script>

<div>
	<h1>Blog</h1>
	<p>Here are all the blogpost listed in the order they where published</p>

	<ul class="grid grid-flow-row-dense grid-cols-3 grid-rows-3">
		{#each posts as post}
			<a href={post.path}>
				<li
					class="border-2 border-zinc-900 bg-white p-5 text-black antialiased hover:border-yellow-500 dark:bg-black dark:text-white"
				>
					<h2>
						{post.meta.title}
					</h2>
					{#if post.meta.image}
						<img src={post.meta.image} alt="img" />
					{/if}
					Published {post.meta.date}
				</li>
			</a>
		{/each}
	</ul>
	{#if displayMore}
		<button onclick={getMorePosts} type="button" class="self-center">Load More Posts</button>
	{/if}
</div>
