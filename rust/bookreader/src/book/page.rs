pub struct Page {
    page_num: usize,
    mimetype: String,
    page: String,
}

impl Page {
    pub fn new(page_num: usize, mimetype: String, page: String) -> Self {
        Self {
            page_num,
            mimetype,
            page,
        }
    }

    pub fn page(&self) -> &str {
        &self.page
    }

    pub fn mimetype(&self) -> &str {
        &self.mimetype
    }
}
