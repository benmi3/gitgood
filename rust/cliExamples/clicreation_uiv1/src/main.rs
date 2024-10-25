use crossterm::{
    cursor,
    style::{self, Stylize},
    terminal, ExecutableCommand, QueueableCommand,
};
use std::io::{self, Result, Write};

fn main() -> Result<()> {
    let mut stdout = io::stdout();
    stdout.execute(terminal::Clear(terminal::ClearType::All))?;
    for y in 0..40 {
        for x in 0..150 {
            if y == 0 || y == 39 || x == 0 || x == 149 {
                stdout
                    .queue(cursor::MoveTo(x, y))?
                    .queue(style::PrintStyledContent("‖".green()))?;
            }
        }
    }
    stdout.flush()?;
    Ok(())
}
