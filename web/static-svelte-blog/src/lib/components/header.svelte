<script lang="ts">
	let pageNum = 0;
</script>

<header>
	<nav>
		<ul>
			<li aria-current={pageNum === 0}>
				<a href="/">Home</a>
			</li>
			<li aria-current={pageNum === 1}>
				<a href="/blog">Contact</a>
			</li>
			<li aria-current={pageNum === 2}>
				<a href="/about">About</a>
			</li>
			<li aria-current={pageNum === 3}>
				<a href="/contact">Contact</a>
			</li>
		</ul>
	</nav>
</header>
