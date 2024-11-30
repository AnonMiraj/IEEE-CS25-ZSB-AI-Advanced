// ﷽
// Contest: Get Ready
//
// Judge: Virtual Judge
// URL: https://vjudge.net/contest/676467#problem/D
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

use std::cmp::*;
use std::io::{self, Write};
fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let s: Vec<char> = input.trim().to_string().chars().collect();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let dis: Vec<i32> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let mut ans = i32::MAX;
    for i in 1..n {
        if s[i - 1] == 'R' && s[i] == 'L' {
            ans = min(((dis[i] - dis[i - 1]) / 2), ans);
        }
    }
    if ans == i32::MAX {
        ans = -1;
    }
    println!("{ans}");
}

fn main() {
    solve();
}
