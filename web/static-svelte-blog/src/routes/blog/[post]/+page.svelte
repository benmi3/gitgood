<script lang="ts">
	import type { PageData } from './$types';

	let { data }: { data: PageData } = $props();
	let hideImage = $state(false);
	function hideImg() {
		hideImage = true;
	}
</script>

<article>
	<h1 class="text-4xl">{data.title}</h1>
	<p class="text-xs">Published: {data.date}</p>
	{#if !hideImage}
		<img class="h-200 w-300 object-contain" src={data.image} alt="img" onerror={hideImg} />
	{/if}
	<div>
		<data.content />
	</div>
	<ul
		class="flex border-2 border-zinc-900 bg-white p-1 text-black antialiased dark:bg-black dark:text-white"
	>
		Categories: {#each data.category as category}
			<li class="flex-auto pl-2">
				<a class="hover:text-yellow-500" href="/api/posts/category/{category}">{category}</a>
			</li>
		{/each}
	</ul>
</article>
