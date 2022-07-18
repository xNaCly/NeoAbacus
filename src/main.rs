use std::io::{stdin, stdout, Write};
use std::process::exit;

extern crate libneoabacus;
mod parser;

const SHELL_PREFIX: &str = ">>";

pub fn shell() {
    loop {
        let mut cmd: String = String::new();
        print!("{} ", SHELL_PREFIX);

        stdout().flush().unwrap();
        stdin().read_line(&mut cmd).unwrap();

        cmd = cmd.trim().to_string();
        if cmd == "exit" {
            exit(0);
        } else {
            let instructions: Vec<String> = parser::parse(&cmd);
            for i in instructions {
                println!("{}", i);
            }
        }
    }
}


fn main() {
    shell();
}
