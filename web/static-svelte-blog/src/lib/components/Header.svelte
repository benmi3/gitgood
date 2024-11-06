<script lang="ts">
	let pageNum: number = 0;
	// function setPage(x: number) {
	// 	pageNum = x;
	// }
</script>

<header class="flex h-10 place-content-center bg-zinc-800 p-4 text-white shadow-lg">
	<nav>
		<ul class="flex justify-around">
			<li class="pr-4" aria-current={pageNum === 0}>
				<a href="/" class="hover:text-yellow-500">Home</a>
			</li>
			<li class="pr-4" aria-current={pageNum === 1}>
				<a href="/blog" class="hover:text-yellow-500">Blog</a>
			</li>
			<li class="pr-4" aria-current={pageNum === 2}>
				<a href="/about" class="hover:text-yellow-500">About</a>
			</li>
			<li class="pr-4" aria-current={pageNum === 3}>
				<a href="/contact" class="hover:text-yellow-500">Contact</a>
			</li>
		</ul>
	</nav>
</header>
