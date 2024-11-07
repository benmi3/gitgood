<script>
	export let data;
</script>

<div>
	<h1 class="text-4xl">Welcome to the blog <br /> This is the latest post:</h1>
	<ul>
		<a href={data.post.path}>
			<li>
				<h2 class="text-2xl">
					{data.post.meta.title}
				</h2>
				{#if data.post.meta.image}
					<img src={data.post.meta.image} alt="img" />
				{/if}
				Published {data.post.meta.date}
			</li>
		</a>
	</ul>
</div>
