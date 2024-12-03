<script lang="ts">
	import { onMount } from 'svelte';
	interface link {
		url: string;
		text: string;
	}
	async function getLinks() {
		const linkRes = await fetch('/api/contact');
		const reslinks = await linkRes.json();
		for (const reslink in reslinks) {
			const parsedLink: link = JSON.parse(reslink);
			links.push(parsedLink);
		}
		return links;
	}

	const links: link[] = [];
	onMount(async () => {
		getLinks();
	});
	// {#each links as link}
	// 				<li><a href={link.url}>{link.text}</a></li>
	// 			{/each}
</script>

<footer class="bottom-0 flex h-10 place-content-center bg-zinc-800 p-4 text-white shadow-lg">
	<nav>
		<ul class="flex justify-around">
			<li class="pr-4 font-bold">
				<a href="/" class="hover:text-yellow-500">Home</a>
			</li>
			<li class="pr-4">
				<a href="/blog" class="hover:text-yellow-500">Blog</a>
			</li>
			<li class="pr-4">
				<a href="/about" class="hover:text-yellow-500">About</a>
			</li>
			<li class="pr-4">
				<a href="/contact" class="hover:text-yellow-500">Contact</a>
			</li>
			{#each links as link}
				<li><a href={link.url}>{link.text}</a></li>
			{/each}
		</ul>
	</nav>
</footer>
