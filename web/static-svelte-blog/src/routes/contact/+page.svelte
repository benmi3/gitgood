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
	{#if !hideImage}
		<img class="h-200 w-300 object-contain" src={data.image} alt="img" onerror={hideImg} />
	{/if}
	<div>
		<data.content />
	</div>
</article>
