extern crate libneoabacus;
use libneoabacus::matrix::{create_matrix, Matrix};

fn main() {
    let m: Matrix = create_matrix(vec![
        vec![1.0, 1.0, 1.0],
        vec![1.0, 1.0, 1.0],
        vec![1.0, 1.0, 1.0],
    ])
    .expect("couldn't create matrix");
    let m1: Matrix = create_matrix(vec![
        vec![1.0, 1.0, 1.0],
        vec![1.0, 1.0, 1.0],
        vec![1.0, 1.0, 1.0],
    ])
    .expect("couldn't create matrix");
    let m2 = m.add(m1);
    m2.print();
}
