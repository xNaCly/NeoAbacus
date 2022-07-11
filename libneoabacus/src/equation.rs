/**
* # solve
> this method returns the x axis crossings for the specifed polynom

 solve expects its params in the following manner:

 ax + bx + cx + dx + e = 0

 ax + bx + cx + d = 0

 ax + bx + c = 0

 ax + b = 0
*/
pub fn solve(a: f64, b: f64, c: f64) -> Option<Vec<f64>> {
    // assign all values NaN values
    let mut roots: Vec<f64> = vec![f64::NAN, f64::NAN, f64::NAN];
    if a != 0.0 && b != 0.0 && c != 0.0 {
    } else if a != 0.0 && b != 0.0 {
        roots[0] = b * (-1.0) / a;
    } else {
        // 0 equation has no crossings with the x axis
        return None;
    }
    return Some(roots);
}

#[cfg(test)]
mod test {
    #[test]
    fn t_solve() {
        let r = crate::equation::solve(0.0, 0.0, 0.0).unwrap();
        assert_eq!(r[0], 0.6);
    }
}
