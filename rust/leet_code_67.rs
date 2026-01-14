struct Solution;

impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let a = a.as_bytes();
        let b = b.as_bytes();

        let mut carry = 0;
        let mut out = String::new();

        let mut idx_a: i32 = a.len() as i32 - 1;
        let mut idx_b: i32 = b.len() as i32 - 1;

        while idx_a >= 0 || idx_b >= 0 || carry > 0 {
            let mut sum = carry;

            if idx_a >= 0 {
                if a[idx_a as usize] == b'1' {
                    sum += 1;
                }
                idx_a -= 1;
            }

            if idx_b >= 0 {
                if b[idx_b as usize] == b'1' {
                    sum += 1;
                }
                idx_b -= 1;
            }

            out.insert(0, if sum % 2 == 0 { '0' } else { '1' });
            carry = sum / 2;
        }

        out
    }
}

fn main() {
    let ans = Solution::add_binary("1010".to_string(), "1011".to_string());
    println!("{ans}");
}
