pub struct Matrix {
    pub height: usize,
    pub width: usize,
    pub values: Vec<Vec<f64>>,
}

pub fn create_matrix(x: Vec<Vec<f64>>) -> Option<Matrix> {
    let xlen: usize = x.len();

    if xlen < 1 {
        return None;
    }

    let ylen: usize = x[0].len();

    // checks if given vectors create too small of a matrix
    if ylen < 2 || xlen < 2 {
        return None;
    }

    // checks if all sub arrays are of equal length
    let mut prev_len = ylen;
    for i in 0..xlen {
        let cur_len = x[i].len();
        if prev_len != cur_len {
            return None;
        }
        prev_len = cur_len;
    }

    Some(Matrix {
        height: ylen,
        width: xlen,
        values: x,
    })
}

impl PartialEq for Matrix {
    fn eq(&self, other: &Self) -> bool {
        let width = self.width == other.width;
        let height = self.height == other.height;
        let mut is_equal: bool = true;

        for i in 0..self.width {
            for j in 0..self.height {
                if self.values[i][j] != other.values[i][j] {
                    is_equal = false;
                }
            }
        }

        return width && height && is_equal;
    }
}

impl Matrix {
    pub fn print(&self) {
        for i in 0..self.width {
            if i == 0 {
                print!("┌────");
            } else {
                print!("┬────");
            }
            if self.width - 1 == i {
                println!("┐");
            }
        }

        for i in 0..self.width {
            for j in 0..self.height {
                print!(
                    "{}{:.2}│",
                    if j == 0 && self.height != 1 {
                        "│"
                    } else {
                        ""
                    },
                    self.values[i][j]
                );
            }
            print!("\n");
        }

        for i in 0..self.width {
            if i == 0 {
                print!("└────");
            } else {
                print!("┴────");
            }
            if self.width - 1 == i {
                println!("┘");
            }
        }
    }

    pub fn trace(&self) -> f64 {
        let mut t: f64 = 0.0;
        for i in 0..self.width {
            for j in 0..self.height {
                if i == j {
                    t += self.values[i][j];
                }
            }
        }
        return t;
    }

    pub fn add(&self, m: Matrix) -> Matrix {
        let mut _m =
            create_matrix(m.values.clone()).expect("creating new matrix to contain sum failed");
        for i in 0..self.width {
            for j in 0..self.height {
                _m.values[i][j] = self.values[i][j] + m.values[i][j];
            }
        }
        return _m;
    }

    pub fn clone(&self) -> Matrix {
        return create_matrix(self.values.clone()).unwrap();
    }
}
