use book::epub::get_book;
use book::Book;

mod book;
mod page;

#[tokio::main]
async fn main() {
    println!("Hello, world!");

    let book_type = String::from("epub");
    let path = String::from("./testfiles/masteringgo.epub");

    let epub_book = get_book(&path).await.unwrap(); // use unwrap for testing

    let title = epub_book.metadata.get("title").unwrap().clone(); // find I way to not need to clone
    let total_pages = epub_book.get_num_pages();

    let mut ready_book = Book::new(title, total_pages, book_type, path, epub_book).unwrap();

    let page_data = ready_book.get_page(2).await.unwrap();
    let print_data = page_data.page();
    println!(" Here is the Page:{}", print_data);
    println!(" Last is the mime type for fun: {}", page_data.mimetype())
}
