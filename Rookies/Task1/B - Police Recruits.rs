// ﷽
// Contest: Get Ready
//
// Judge: Virtual Judge
// URL: https://vjudge.net/contest/676467#problem/B
// Memory Limit: 256
// Time Limit: 1000
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
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().parse::<i32>().unwrap();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();

    let v: Vec<i32> = input
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let mut ans = 0;
    let mut police = 0;
    for i in &v {
        if i == &-1 {
            if police > 0 {
               police -= 1;
            } else {
                ans += 1;
            }
        } else {
            police += i;
        }
    }
    println!("{ans}");
    dbg!(v);
}

fn main() {
    solve();
}
