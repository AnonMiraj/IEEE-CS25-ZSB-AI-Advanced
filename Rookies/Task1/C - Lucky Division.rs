// ﷽
// Contest: Get Ready
//
// Judge: Virtual Judge
// URL: https://vjudge.net/contest/676467#problem/C
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
// Comments : learning new language is cool

use std::io::{self, Write};
fn islucky(num : i32, luck : i32, count : i32) -> bool {
    if count ==5
    {
        return false;
    }
    if luck != 0 && num%luck == 0 
    {
        return true;
    }

    return islucky(num,luck*10 + 4,count +1) || islucky(num,luck*10 + 7,count +1);

}

fn solve() {
    let mut n : i32;
    let mut input = String::new ();
    io::stdin().read_line(&mut input).unwrap();
    n = input.trim().parse::<i32>().unwrap();

    if islucky(n,0,0) == true{

    println!("YES");

    }
    else
    {
    println!("NO");
    }


}

fn main() {
    solve();
}
