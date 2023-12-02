use std::collections::HashMap;
use std::fs::File;
use std::io::{self, prelude::*, BufReader};

fn main() -> io::Result<()> {
    let file = File::open("./input2.txt")?;
    let reader = BufReader::new(file);

    let mut my_map = HashMap::new();

    my_map.insert("one", '1');
    my_map.insert("two", '2');
    my_map.insert("three", '3');
    my_map.insert("four", '4');
    my_map.insert("five", '5');
    my_map.insert("six", '6');
    my_map.insert("seven", '7');
    my_map.insert("eight", '8');
    my_map.insert("nine", '9');

    let mut skip_count: i32 ;
    let mut beg: char;
    let mut end: char;
    let mut sum: u32 = 0;
    let mut result: char;

    for line_result in reader.lines() {
        let line = line_result?;
        beg = '0';
        end = '0';
        result = '0';
        for (index, c) in line.chars().enumerate() {
                    skip_count = 0;

            if c >= '0' && c <= '9' {
                println!("{}", c);

                result = c;
            }
            if index + 2 < line.len() && skip_count==0 {
                let next_two_chars = &line[index..index + 3];
                let temp_key = next_two_chars;
                if my_map.contains_key(&temp_key) {
                    if let Some(value) = my_map.get(temp_key) {
                        println!("{}", temp_key);
                        result = *value;
                    }
                    skip_count = 2;
                }
            }
            if index + 3 < line.len()&& skip_count==0 {
                let next_two_chars = &line[index..index + 4];
                let temp_key = next_two_chars;
                if my_map.contains_key(&temp_key) {
                    if let Some(value) = my_map.get(temp_key) {
                        println!("{}", temp_key);
                        result = *value;
                    }
                    skip_count = 3;
                }
            }
            if index + 4 < line.len()&& skip_count==0 {
                let next_two_chars = &line[index..index + 5];
                let temp_key = next_two_chars;
                if my_map.contains_key(&temp_key) {
                    if let Some(value) = my_map.get(temp_key) {
                        println!("{}", temp_key);
                        result = *value;
                    }
                }
            }
            if beg == '0' {
                beg = result;
            }
            end = result;
        }
        let num = beg.to_digit(10).unwrap() * 10 + end.to_digit(10).unwrap();

        println!("Num: {}", num);
        sum += num;
    }
    println!("Sum: {}", sum);
    Ok(())
}
