export async function load({ params }) {
  const post = await import(`./contact.md`);
  const { title, date, image, links } = post.metadata;
  const content = post.default;


  return {
    content,
    title,
    image,
    date,
    links,
  };
}
