// ﷽
// Contest: Get Ready
//
// Judge: Virtual Judge
// URL: https://vjudge.net/contest/676467#problem/E
// Memory Limit: 256
// Time Limit: 2000
// Start: Sat 30 Nov 2024 09:44:25 AM EET
// Reading Time :
// Thinking Time :
// Coding Time :
// Debug Time :
// Submit Count :
// Problem Level :
// Category :
// Comments :

use std::io::{self};

fn solve() {
    let qwerty: Vec<char> = "qwertyuiopasdfghjkl;zxcvbnm,./"
        .trim()
        .to_string()
        .chars()
        .collect();
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: char = input.trim().parse().unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let s: Vec<char> = input.trim().to_string().chars().collect();
    if n == 'R' {
        for i in s {
            for j in (0..30).rev() {
                if qwerty[j] == i {
                    print!("{}", qwerty[j - 1]);
                }
            }
        }
    } else {
        for i in s {
            for j in (0..30) {
                if qwerty[j] == i {
                    print!("{}", qwerty[j + 1]);
                }
            }
        }
    }
}

fn main() {
    solve();
}
