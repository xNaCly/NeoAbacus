#[cfg(test)]
mod test {
    use libneoabacus::matrix::{create_matrix, Matrix};

    #[test]
    fn test_matrix_create() {
        let m: Matrix = create_matrix(vec![vec![2.0, 2.0], vec![2.0, 2.0]]).unwrap();
        assert!(
            m.height == 2 && m.width == 2,
            "matrix height and width should be 2"
        );
    }
    #[test]
    fn test_matrix_create_fail() {
        let m = create_matrix(vec![]);
        assert!(
            m.is_none(),
            "matrix creation with not enough vectors should fail"
        );
    }

    #[test]
    fn test_matrix_trace() {
        let m: Matrix = create_matrix(vec![
            vec![3.0, 3.0, 3.0],
            vec![3.0, 3.0, 3.0],
            vec![3.0, 3.0, 3.0],
        ])
        .unwrap();
        assert_eq!(m.trace(), 9.0, "matrix trace should be 9.0");
    }

    #[test]
    fn test_matrix_add() {
        let m0: Matrix = create_matrix(vec![
            vec![2.0, 4.0, 6.0],
            vec![2.0, 4.0, 6.0],
            vec![2.0, 4.0, 6.0],
        ])
        .unwrap();
        let m: Matrix = create_matrix(vec![
            vec![1.0, 2.0, 3.0],
            vec![1.0, 2.0, 3.0],
            vec![1.0, 2.0, 3.0],
        ])
        .unwrap();
        let m1 = m.add(m.clone());
        assert!(m1 == m0);
    }

    #[test]
    fn test_matrix_sub() {
        let m0: Matrix = create_matrix(vec![
            vec![0.0, 0.0, 0.0],
            vec![0.0, 0.0, 0.0],
            vec![0.0, 0.0, 0.0],
        ])
        .unwrap();
        let m: Matrix = create_matrix(vec![
            vec![1.0, 2.0, 3.0],
            vec![1.0, 2.0, 3.0],
            vec![1.0, 2.0, 3.0],
        ])
        .unwrap();
        let m1 = m.sub(m.clone());
        assert!(m1 == m0);
    }
}
