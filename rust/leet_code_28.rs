struct Solution;

impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        if needle.is_empty() {
            return 0;
        }
        match haystack.find(&needle) {
            Some(i) => i as i32,
            None => -1,
        }
    }
}


fn main() {
    let ans = Solution::str_str("hello".to_string(), "ll".to_string());
    println!("{ans}");
}

