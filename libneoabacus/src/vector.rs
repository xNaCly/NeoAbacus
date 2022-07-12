pub struct Vector {
    pub x: f64,
    pub y: f64,
    pub z: f64,
}

impl PartialEq for Vector {
    fn eq(&self, other: &Self) -> bool {
        return self.x == other.x && self.y == other.y && self.z == other.z;
    }
}

impl Vector {
    pub fn clone(&self) -> Vector {
        return Vector {
            x: self.x,
            y: self.y,
            z: self.z,
        };
    }

    pub fn len(&self) -> f64 {
        return (self.x.powf(2.0) + self.y.powf(2.0) + self.z.powf(2.0)).sqrt();
    }

    pub fn add(&self, other: Vector) -> Vector {
        return Vector {
            x: self.x + other.x,
            y: self.y + other.y,
            z: self.z + other.z,
        };
    }

    pub fn sub(&self, other: Vector) -> Vector {
        return Vector {
            x: self.x - other.x,
            y: self.y - other.y,
            z: self.z - other.z,
        };
    }
}
