use std::fs::File;
use std::io::{self, prelude::*, BufReader};

struct Game {
    id: u32,
    red: u32,
    blue: u32,
    green: u32,
}

fn main() -> io::Result<()> {
    let file = File::open("./input2.txt")?;
    let reader = BufReader::new(file);
    let mut game = Game {
        id: 1,
        red: 0,
        blue: 0,
        green: 0,
    };
    let mut sum: u32 = 0;
    for line_res in reader.lines() {
        let line = line_res?;
        let mut parts = line.splitn(2, ':');
        if let Some(second_part) = parts.nth(1) {
            println!("{}", second_part);
            let parts: Vec<&str> = second_part.split(';').collect();

            parts.iter().enumerate().for_each(|(index, part)| {
                if let Some(index) = part.find("red") {
                    let st = &part[index - 3..index];
                    let mst = &st.replace(" ", "");

                    match mst.parse::<u32>() {
                        Ok(result) => {
                            // Successfully converted to u32
                            // println!("red {}", result);
                            game.red = std::cmp::max(game.red, result);
                        }
                        Err(_) => {
                            // Conversion failed
                            println!("Failed to convert to u32");
                        }
                    }
                }
                if let Some(index) = part.find("blue") {
                    let st = &part[index - 3..index];
                    let mst = &st.replace(" ", "");

                    match mst.parse::<u32>() {
                        Ok(result) => {
                            // Successfully converted to u32
                            // println!("blue {}", result);
                            game.blue = std::cmp::max(game.blue, result);
                        }
                        Err(_) => {
                            // Conversion failed
                            println!("Failed to convert to u32");
                        }
                    }
                }
                if let Some(index) = part.find("green") {
                    let st = &part[index - 3..index];
                    let mst = &st.replace(" ", "");

                    match mst.parse::<u32>() {
                        Ok(result) => {
                            // Successfully converted to u32
                            // println!("green {}", result);
                            game.green = std::cmp::max(game.green, result);
                        }
                        Err(_) => {
                            // Conversion failed
                            println!("Failed to convert to u32");
                        }
                    }
                }
            });
        } else {
            println!("No colon found in the string");
        }
        // println!("{} {} {}", game.red, game.blue, game.green);
        sum += game.red*game.blue*game.green;
        game.red = 0;
        game.blue = 0;
        game.green = 0;
        game.id += 1;
    }
    println!("sum = {}", sum);
    Ok(())
}
