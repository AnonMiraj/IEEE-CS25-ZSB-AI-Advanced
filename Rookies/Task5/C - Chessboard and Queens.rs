use std::io::{self, BufRead};

fn nice(row: usize, col: usize, queens: &Vec<isize>, blocked: &Vec<Vec<bool>>) -> bool {
    if blocked[row][col] {
        return false;
    }
    for i in 0..row {
        if queens[i] == col as isize
            || (queens[i] - col as isize).abs() == (i as isize - row as isize).abs()
        {
            return false;
        }
    }
    true
}

fn f(
    row: usize,
    queens: &mut Vec<isize>,
    blocked: &Vec<Vec<bool>>,
    solution_count: &mut usize,
) {
    if row == 8 {
        *solution_count += 1;
        return;
    }

    for col in 0..8 {
        if nice(row, col, queens, blocked) {
            queens[row] = col as isize;
            f(row + 1, queens, blocked, solution_count);
            queens[row] = -1;
        }
    }
}

fn main() {
    let stdin = io::stdin();
    let mut blocked = vec![vec![false; 8]; 8];

    for (i, line) in stdin.lock().lines().enumerate() {
        let line = line.unwrap();
        for (j, ch) in line.chars().enumerate() {
            blocked[i][j] = ch == '*';
        }
    }

    let mut queens = vec![-1; 8];
    let mut solution_count = 0;
    f(0, &mut queens, &blocked, &mut solution_count);

    println!("{}", solution_count);
}
