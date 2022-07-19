macro_rules! log {
    ($($arg:tt)*) => {
      println!("[LOG] {}", $($arg)*);
    };
}
macro_rules! debug {
    ($($arg:tt)*) => {
      println!("[DEBUG] {}", $($arg)*);
    };
}
macro_rules! err {
    ($($arg:tt)*) => {
      println!("[Err] {}", $($arg)*);
    };
}
