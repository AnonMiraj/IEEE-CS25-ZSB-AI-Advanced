//﷽
// Contest: Get Ready
//
// Judge: Virtual Judge
// URL: https://vjudge.net/contest/676467#problem/A
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

use std::io::{self, Write};

fn solve() {
    let mut n = 1;
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    n = input.trim().parse::<usize>().unwrap();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();

    let mut v: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let mut svi: usize = 0;
    let mut bvi: usize = 0;
    for i in 0_usize..n {
        if v[svi] >= v[i] {
            svi = i;
        }
        if v[bvi] < v[i] {
            bvi = i;
        }
    }

    let ans = (n - svi - 1) + bvi - if bvi > svi { 1 } else { 0 };
    println!("{ans}");
}

fn main() {
    let mut n = 1;
    for _ in 0..n {
        solve();
    }
}
