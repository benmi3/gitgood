use crate::book::Book;
use crate::book::Page;
use crate::book::{Error, Result};
use epub::doc::EpubDoc;
use std::fs::File;
use std::io::BufReader;

pub async fn get_book(path: &str) -> Result<EpubDoc<BufReader<File>>> {
    Ok(EpubDoc::new(path)?)
}

impl Book<EpubDoc<BufReader<File>>> {
    pub async fn get_page(&mut self, pagenum: usize) -> Result<Page> {
        self.book.set_current_page(pagenum);
        if let Some((book_page, mimetype)) = self.book.get_current_str() {
            return Ok(Page::new(pagenum, mimetype, book_page));
        }
        Err(Error::PageNotFound)
    }
}
