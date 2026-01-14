struct Solution;

impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        match s.split_whitespace().last() {
            None => 0,
            Some(w) => w.len() as i32,
        }
    }
}


fn main() {
    let ans = Solution::length_of_last_word("   fly me   to   the moon  ".to_string());
    println!("{ans}");
}
