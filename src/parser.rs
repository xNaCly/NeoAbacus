use regex::*;

#[derive(Debug, PartialEq, Eq)]
pub enum TokenKind {
    Int, // always f64
    Sin,
    Cos,
    Mul,
    Sub,
    Add,
    Div,
    Pow,
    Root,
    Var, // variables such as x, y, z
    Empty,
}
pub struct Token {
    kind: TokenKind,
    value: Option<f64>,
    name: Option<String>,
}

impl ToString for Token {
    fn to_string(&self) -> String {
        return format!(
            "[TokenKind::{:?}, {}, {}]",
            self.kind,
            match self.value {
                Some(x) => x.to_string(),
                None => String::new(),
            },
            match &self.name {
                Some(x) => x.to_string(),
                None => String::new(),
            }
        );
    }
}

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

pub fn parse(str: String) -> Vec<Token> {
    let var_regex: Regex = Regex::new(r"([a-z])").expect("invalid regex");
    let int_regex: Regex = Regex::new(r"([0-9])").expect("invalid regex");
    let mut tokens: Vec<Token> = Vec::new();
    let mut new_str = str.clone();
    new_str = new_str.trim().to_string();
    let str_split: Vec<&str> = new_str.split("").collect();

    let mut temp = String::new();
    for (index, &i) in str_split.iter().enumerate() {
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
