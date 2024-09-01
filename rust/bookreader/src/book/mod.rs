pub mod epub;
mod error;
mod page;

pub use self::error::{Error, Result};
pub use self::page::Page;

pub struct Book<BookType> {
    title: Vec<String>,
    total_pages: usize,
    book_type: String,
    path: String,
    book: BookType,
}

impl<BookType> Book<BookType> {
    pub fn new(
        title: Vec<String>,
        total_pages: usize,
        book_type: String,
        path: String,
        book: BookType,
    ) -> Result<Self> {
        Ok(Self {
            title,
            total_pages,
            book_type,
            path,
            book,
        })
    }
}
