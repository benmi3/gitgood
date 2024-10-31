<script lang="ts">
	let pageNum = 0;
</script>

<header class="bg-blue-800 p-4 text-white shadow-lg">
	<nav>
		<ul class="flex justify-around">
			<li class="font-bold" aria-current={pageNum === 0}>
				<a href="/" class="hover:text-yellow-500">Home</a>
			</li>
			<li aria-current={pageNum === 1}>
				<a href="/blog" class="hover:text-yellow-500">Contact</a>
			</li>
			<li aria-current={pageNum === 2}>
				<a href="/about" class="hover:text-yellow-500">About</a>
			</li>
			<li aria-current={pageNum === 3}>
				<a href="/contact" class="hover:text-yellow-500">Contact</a>
			</li>
		</ul>
	</nav>
</header>
