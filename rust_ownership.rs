// Rust: Memory Management - Ownership and Borrowing Demo

fn main() {
    println!("=== OWNERSHIP DEMO ===");
    
    // Each value has exactly ONE owner
    let s1 = String::from("hello");
    println!("s1 owns the string: {}", s1);
    
    // Ownership is MOVED to s2 — s1 is no longer valid
    let s2 = s1;
    println!("s2 now owns the string: {}", s2);
    // println!("{}", s1); // This line would cause a COMPILE ERROR
    // "value borrowed here after move"
    
    println!("\n=== BORROWING DEMO ===");
    
    // Borrowing: pass a reference without transferring ownership
    let s3 = String::from("world");
    let length = get_length(&s3);   // s3 is BORROWED not moved
    println!("String: '{}' has length: {}", s3, length);
    // s3 is still valid here because we only borrowed it
    
    println!("\n=== MUTABLE BORROWING DEMO ===");
    
    let mut s4 = String::from("hello");
    println!("Before mutation: {}", s4);
    add_text(&mut s4);              // mutable borrow
    println!("After mutation: {}", s4);
    
    println!("\n=== AUTOMATIC MEMORY CLEANUP ===");
    
    {
        let scoped = String::from("I exist in this block only");
        println!("Inside block: {}", scoped);
    } // scoped is DROPPED here automatically — memory freed
    
    println!("scoped variable has been automatically freed");
    println!("No garbage collector needed!");
    
    println!("\n=== CLONE DEMO (explicit copy) ===");
    
    let original = String::from("original");
    let cloned = original.clone();  // explicit deep copy
    println!("Original: {}", original);
    println!("Cloned:   {}", cloned);
    // Both are valid because clone makes a full independent copy
}

fn get_length(s: &String) -> usize {
    s.len()   // s is a reference, no ownership taken
}             // s goes out of scope but memory is NOT freed
              // because Rust only frees memory owned values

fn add_text(s: &mut String) {
    s.push_str(", world");  // mutates via mutable reference
}