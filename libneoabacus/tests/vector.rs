#[cfg(test)]
mod test {
    use libneoabacus::vector::Vector;
    #[test]
    fn test_vector_len() {
        let v = Vector {
            x: 3.0,
            y: 4.0,
            z: 0.0,
        };
        assert_eq!(v.len(), 5.0);
    }

    #[test]
    fn test_vector_add() {
        let v = Vector {
            x: 1.0,
            y: 1.0,
            z: 1.0,
        };
        let r = Vector {
            x: 2.0,
            y: 2.0,
            z: 2.0,
        };
        let v1 = v.add(v.clone());
        assert!(r == v1)
    }

    #[test]
    fn test_vector_sub() {
        let v = Vector {
            x: 1.0,
            y: 1.0,
            z: 1.0,
        };
        let r = Vector {
            x: 0.0,
            y: 0.0,
            z: 0.0,
        };
        let v1 = v.sub(v.clone());
        assert!(r == v1)
    }
}
