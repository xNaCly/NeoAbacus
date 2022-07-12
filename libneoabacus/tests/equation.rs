#[cfg(test)]
mod test {
    use libneoabacus::equation::*;
    #[test]
    fn test_solve_linear() {
        let r = solve(-5.0, 3.0, 0.0).unwrap();
        assert_eq!(r[0], 0.6);
    }
    #[test]
    fn test_solve_quadratic() {
        let r = solve(2.0, -8.0, 6.0).unwrap();
        assert_eq!(r[0], 1.0);
        assert_eq!(r[1], 3.0);
    }
}
