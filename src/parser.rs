use regex::*;

#[derive(Debug, PartialEq, Eq)]
pub enum TokenKind {
    /// All integers are internally of type f64
    Int,
    /// Sinus type
    Sin,
    /// Cosinus type
    Cos,
    /// Multiplication
    Mul,
    /// Subtraction
    Sub,
    /// Addition
    Add,
    /// Division
    Div,
    /// Power (x^n)
    Pow,
    /// Root such as square root
    Root,
    /// Variables such as x, y, z
    Var,
    /// Bracket '('
    BracketOpen,
    /// Bracket ')'
    BracketClose,
    /// Placeholder
    Empty,
}
/// Token representation
#[derive(Debug)]
pub struct Token {
    kind: TokenKind,
    /// holds the value of the token if its of type [TokenKind::Int]
    value: Option<f64>,
    /// only intended for variables to store their names, eg. x,y,z
    name: Option<String>,
}

impl ToString for Token {
    fn to_string(&self) -> String {
        return format!(
            "[TokenKind::{:?}, {}, {}]",
            self.kind,
            match self.value {
                Some(x) => x,
                None => f64::NAN,
            },
            match &self.name {
                Some(x) => x.to_string(),
                None => String::new(),
            }
        );
    }
}

/// parses given string to the respective float representation
/// returns a Token
fn parse_ints(s: &str) -> Token {
    let mut t = Token {
        value: None,
        kind: TokenKind::Empty,
        name: None,
    };
    match s.parse::<f64>() {
        Ok(f) => {
            t.value = Some(f);
            t.kind = TokenKind::Int;
        }
        Err(_) => {
            t.kind = TokenKind::Empty;
            t.value = None;
        }
    }
    return t;
}

/// takes a string and tries to return a vector of tokens parsed from the given string
///
/// currently supports all enum values in [TokenKind] except sin and cos.
///
/// I/O - Examples:
/// ```
/// parse("2+1");
/// // [
/// //    Token {
/// //        kind: Int,
/// //        value: Some(
/// //            2.0,
/// //        ),
/// //        name: None,
/// //    },
/// //    Token {
/// //        kind: Add,
/// //        value: None,
/// //        name: None,
/// //    },
/// //    Token {
/// //        kind: Int,
/// //        value: Some(
/// //            1.0,
/// //        ),
/// //        name: None,
/// //    },
/// // ]
/// parse("525*0.13-123.09/250009");
/// //[
/// //    Token {
/// //        kind: Int,
/// //        value: Some(
/// //            525.0,
/// //        ),
/// //        name: None,
/// //    },
/// //    Token {
/// //        kind: Mul,
/// //        value: None,
/// //        name: None,
/// //    },
/// //    Token {
/// //        kind: Int,
/// //        value: Some(
/// //            0.13,
/// //        ),
/// //        name: None,
/// //    },
/// //    Token {
/// //        kind: Sub,
/// //        value: None,
/// //        name: None,
/// //    },
/// //    Token {
/// //        kind: Int,
/// //        value: Some(
/// //            123.09,
/// //        ),
/// //        name: None,
/// //    },
/// //    Token {
/// //        kind: Div,
/// //        value: None,
/// //        name: None,
/// //    },
/// //    Token {
/// //        kind: Int,
/// //        value: Some(
/// //            250009.0,
/// //        ),
/// //        name: None,
/// //    },
/// //]
/// ```
pub fn parse(str: String) -> Vec<Token> {
    let var_regex: Regex = Regex::new(r"([a-z])").expect("invalid regex");
    let int_regex: Regex = Regex::new(r"([0-9]|\.)").expect("invalid regex");
    let mut tokens: Vec<Token> = Vec::new();
    let mut new_str = str.clone();
    new_str = new_str.trim().to_string();
    let str_split: Vec<&str> = new_str.split("").collect();

    let mut temp = String::new();
    for (index, &i) in str_split.iter().enumerate() {
        // if no more symbols available in string, push remaning numbers parsed into token vector
        if !temp.is_empty() && index == str_split.len() - 1 {
            tokens.push(parse_ints(&temp));
        }

        if i.is_empty() || i == " " {
            continue;
        }

        let mut t = Token {
            kind: TokenKind::Empty,
            value: None,
            name: None,
        };

        match i {
            "(" => {
                if !temp.is_empty() {
                    tokens.push(parse_ints(&temp));
                    temp.clear()
                }
                t.kind = TokenKind::BracketOpen;
            }
            ")" => {
                if !temp.is_empty() {
                    tokens.push(parse_ints(&temp));
                    temp.clear()
                }
                t.kind = TokenKind::BracketClose;
            }
            "+" => {
                if !temp.is_empty() {
                    tokens.push(parse_ints(&temp));
                    temp.clear()
                }
                t.kind = TokenKind::Add;
            }
            "-" => {
                if !temp.is_empty() {
                    tokens.push(parse_ints(&temp));
                    temp.clear()
                }
                t.kind = TokenKind::Sub
            }
            "*" => {
                if !temp.is_empty() {
                    tokens.push(parse_ints(&temp));
                    temp.clear()
                }
                t.kind = TokenKind::Mul;
            }
            "/" => {
                if !temp.is_empty() {
                    tokens.push(parse_ints(&temp));
                    temp.clear()
                }
                t.kind = TokenKind::Div
            }
            "^" => {
                if !temp.is_empty() {
                    tokens.push(parse_ints(&temp));
                    temp.clear()
                }
                t.kind = TokenKind::Pow
            }
            _ => {
                /* if i is integer append it to the temp string
                  else if i is a variable:
                    if temp string has content, push all numbers, afterwars clear string
                    push variable token
                */
                if int_regex.is_match(i) {
                    temp.push_str(i);
                } else if var_regex.is_match(i) {
                    if !temp.is_empty() {
                        tokens.push(parse_ints(&temp));
                        temp.clear();
                    }
                    tokens.push(Token {
                        kind: TokenKind::Var,
                        value: None,
                        name: Some(i.to_string()),
                    });
                }
                continue;
            }
        }
        tokens.push(t);
    }
    return tokens;
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_parse_addition_single_char_ints() {
        let i = "2+1";
        let r = parse(i.to_string());
        assert_eq!(r[0].value.unwrap(), 2.0);
        assert!(r[1].kind == TokenKind::Add);
        assert_eq!(r[2].value.unwrap(), 1.0);
    }

    #[test]
    fn test_parse_addition_multi_char_ints() {
        let i = "20+11";
        let r = parse(i.to_string());
        assert_eq!(r[0].value.unwrap(), 20.0);
        assert!(r[1].kind == TokenKind::Add);
        assert_eq!(r[2].value.unwrap(), 11.0);
    }
}
