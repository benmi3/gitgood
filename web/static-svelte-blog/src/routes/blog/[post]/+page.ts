export async function load({ params }) {
  const post = await import(`../${params.post}.md`);
  const { title, date, category, image } = post.metadata;
  const content = post.default;


  return {
    content,
    title,
    image,
    date,
    category
  };
}
