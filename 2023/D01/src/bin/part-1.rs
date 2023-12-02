use std::fs::File;
use std::io::{self, prelude::*, BufReader};

fn main() -> io::Result<()> {
    let file = File::open("./input1.txt")?;
    let reader = BufReader::new(file);

    let mut beg: char;
    let mut end: char;
    let mut _sum: u32 = 0;
    for line in reader.lines() {
        beg = '0';
        end = '0';
        for c in line?.chars() {
            if c >= '0' && c <= '9' {
                if beg == '0' {
                    beg = c;
                }
                end = c;
            }
        }
        let num = beg.to_digit(10).unwrap() * 10 + end.to_digit(10).unwrap();

        
        _sum += num;
    }
        println!("Sum: {}", _sum);
    Ok(())
        
}
