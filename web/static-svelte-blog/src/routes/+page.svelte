<script lang="ts">
	import type { PageData } from './$types';

	let { data }: { data: PageData } = $props();
</script>

<div>
	<h1 class="text-4xl">Welcome to the blog <br /> This is the latest post:</h1>
	<ul>
		<a href={data.path}>
			<li>
				<h2 class="text-2xl">
					{data.post.title}
				</h2>
				{#if data.post.image}
					<img src={data.post.image} alt="img" />
				{/if}
				Published {data.post.date}
			</li>
		</a>
	</ul>
</div>
