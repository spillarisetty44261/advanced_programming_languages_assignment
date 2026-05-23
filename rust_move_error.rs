fn main() {
    let s1 = String::from("hello");
    let s2 = s1;          // ownership moved to s2
    println!("{}", s1);   // ERROR: s1 no longer valid
}