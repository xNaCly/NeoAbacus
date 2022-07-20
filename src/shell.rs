use super::parser::*;
use std::io::{stdin, stdout, Write};
use std::process::exit;

const SHELL_PREFIX: &str = ">>";

/* TODO:
- print the time it took to exectue the parser and to calculate
 */
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
            let instructions: Vec<Token> = parse(cmd);
            println!("{:#?}", instructions);
        }
    }
}
