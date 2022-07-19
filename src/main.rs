extern crate libneoabacus;

#[macro_use]
mod logger;
mod parser;
mod shell;
use shell::shell;

fn main() {
    shell();
}
