use std::io::{self, Read};
use std::cmp::min;

fn read_line() -> Vec<i32> {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    return buf.trim().split(" ")
        .map(|x| {x.parse::<i32>().unwrap() })
        .collect();
}

fn get_ans (a : i32, b : i32, c : i32, d : i32) -> i32{
    let ans = -1;
    
    for i in 0..101{
        for j in 0..101{
            if (a*i + b == c*j + d){
                return a*i + b;
            }
        }
    }
    
    return 0x3f3f3f3f;
}


fn main(){
    let mut line = read_line();
    let (a, b) = (line[0], line[1]);
    line = read_line();
    let (c, d) = (line[0], line[1]);
        
    let mut ans = 0x3f3f3f3f;

    ans = min (get_ans(c, d, a, b), get_ans(a, b, c, d));
    if (ans == 0x3f3f3f3f){
        println! ("-1");
    }
    else{
        println! ("{}", ans);
    }
    
}
