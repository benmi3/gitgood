use derive_more::From;
use serde::Serialize;
use serde_with::{serde_as, DisplayFromStr};

pub type Result<T> = core::result::Result<T, Error>;

#[serde_as]
#[derive(Debug, Serialize, From)]
pub enum Error {
    // TODO: Need fixing
    // -- Externals
    #[from]
    ShtcxEsp(#[serde_as(as = "DisplayFromStr")] shtcx::Error<esp_idf_svc::hal::io::EspIOError>),
    #[from]
    ShtcxI2c(#[serde_as(as = "DisplayFromStr")] shtcx::Error<esp_idf_svc::hal::i2c::I2cError>),
}
// region:    --- Error Boilerplate
impl core::fmt::Display for Error {
    fn fmt(&self, fmt: &mut core::fmt::Formatter) -> core::result::Result<(), core::fmt::Error> {
        write!(fmt, "{self:?}")
    }
}
impl std::error::Error for Error {}
// endregion: --- Error Boilerplate
