fn perm_is_palindrome(str: &String) -> bool {
    let mut bit_set: u128 = 0;

    str.chars().for_each(|c| {
        bit_set ^= 1 << c as u8;
    });

    (bit_set & bit_set - 1) == 0
}

fn main() {
    assert!(perm_is_palindrome(&String::from("civic")));
    assert!(perm_is_palindrome(&String::from("zenzone")));
    // assert!(perm_is_palindrome(&String::from("~©©~")));
}
