<script lang="ts">
	import '../app.css';
	let { children } = $props();
	import Header from '$lib/components/Header.svelte';
	import Footer from '$lib/components/Footer.svelte';
</script>

<div class="flex h-screen flex-col">
	<Header></Header>
	<div
		class="flex flex-1 place-content-center overflow-auto bg-white text-black antialiased dark:bg-gray-950 dark:text-white"
	>
		{@render children()}
	</div>
	<Footer></Footer>
</div>
