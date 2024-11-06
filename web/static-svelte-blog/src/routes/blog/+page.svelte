<script>
	export let data;
</script>

<div>
	<h1>Blog</h1>
	<p>Here are all the blogpost listed in the order they where published</p>
	<ul class="grid grid-flow-row-dense grid-cols-3 grid-rows-3">
		{#each data.posts as post}
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
</div>
