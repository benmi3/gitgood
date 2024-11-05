<script>
	export let data;
</script>

<article>
	<h1>{data.title}</h1>
	{#if data.image}
		<img src={data.image} alt="img" />
	{/if}
	<p>Published: {data.date}</p>
	<svelte:component this={data.content} />
	<ul>
		Categories: {#each data.category as category}
			<li><a href="/api/posts/category/{category}">{category}</a></li>
		{/each}
	</ul>
</article>
