struct Solution;

impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut dif = 10.0;
        let mut ans = (x / 2) as f64;

        while dif > 0.01 {
            dif = ans - 0.5 * (ans + x as f64 / ans);
            ans = 0.5 * (ans + x as f64 / ans);
        }

        ans.floor() as i32
    }
}

fn main() {
    let ans = Solution::my_sqrt(16);

    println!("{ans}");
}
