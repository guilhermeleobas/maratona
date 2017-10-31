use std::io;

fn read_line() -> Vec<i64> {

  let mut buf = String::new();
  io::stdin().read_line(&mut buf).unwrap();
  return buf.trim().split(" ")
    .map(|x| {x.parse::<i64>().unwrap() })
    .collect();
}

fn main (){
  let line = read_line();
  let (a, b) = (line[0], line[1]);
  let x = a/b;
  
  if (x % 2 == 0){
      println! ("NO");
  }
  else{
      println! ("YES");
  }
}
