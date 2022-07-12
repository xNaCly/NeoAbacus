use std::io::{stdin, stdout, Write};
use std::process::exit;

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
        }

        println!("{}", cmd);
    }
}
