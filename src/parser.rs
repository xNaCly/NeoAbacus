enum TokenKind {
    Add,
    Sub,
    Mult,
    Div
}

struct Token {
    value: String,
    kind: TokenKind,
}

pub fn parse(s: &str) -> Vec<String>{
    let n_str = s.replace("\n", "");
    let mut v: Vec<String> = Vec::new();

    for i in n_str.split("") {
        v.push(i.to_string());
    }

    return v;
}
