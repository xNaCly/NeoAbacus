/**
Prints given argument list prefixed with "\[LOG\]"

```
log!("i", "am", "a", "log", 1, 2, 3); // prints: [LOG] i am a log 1 2 3
```
*/
macro_rules! log {
    ($($arg:expr),*) => {{
      print!("[LOG] ");
      $(
        print!("{} ", $arg);
      )*
      println!();
    }};
}
/**
Prints given argument list prefixed with "\[DEBUG\]"

```
debug!("i", "am", "a", "log", 1, 2, 3);
```
*/
macro_rules! debug {
    ($($arg:expr),*) => {{
      print!("[DEBUG] ");
      $(
        print!("{} ", $arg);
      )*
      println!();
    }};
}
/**
Prints given argument list prefixed with "\[ERR\]"

```
err!("i", "am", "a", "log", 1, 2, 3);
```
*/
macro_rules! err {
    ($($arg:expr),*) => {{
      print!("[ERR] ");
      $(
        print!("{} ", $arg);
      )*
      println!();
    }};
}
