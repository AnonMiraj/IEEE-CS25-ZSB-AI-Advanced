fn main() {
    let mut scan = Scanner::default();

    let n: usize = scan.next();
    let mut g = vec![vec![]; n];
    for _ in 1..n {
        let (u, v, c): (usize, usize, u32) = (scan.next(), scan.next(), scan.next());
        g[u].push((v, c));
        g[v].push((u, c));
    }

    println!("{}", max_cst(&g, 0, 0));
}

fn max_cst(g: &[Vec<(usize, u32)>], u: usize, p: usize) -> u32 {
    g[u].iter()
        .filter(|&&(v, _)| v != p)
        .map(|&(v, c)| c + max_cst(g, v, u))
        .max()
        .unwrap_or(0)
}

#[derive(Default)]
struct Scanner {
    buf: Vec<String>,
}

impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        if let Some(token) = self.buf.pop() {
            return token.parse().ok().expect("Failed parse");
        }

        let mut ln = String::new();
        std::io::stdin().read_line(&mut ln).expect("Failed read");

        self.buf = ln.split_whitespace().rev().map(String::from).collect();

        self.next()
    }
}
