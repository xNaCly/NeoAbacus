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
        let t0: f64 = b * (-1.0) - f64::sqrt(f64::powf(b, 2.0) - (4.0 * a * c));
        let t1: f64 = b * (-1.0) + f64::sqrt(f64::powf(b, 2.0) - (4.0 * a * c));
        roots[0] = t0 / (2.0 * a);
        roots[1] = t1 / (2.0 * a);
    } else if a != 0.0 && b != 0.0 {
        roots[0] = b * (-1.0) / a;
    } else {
        // 0 equation has no crossings with the x axis
        return None;
    }
    return Some(roots);
}
