struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut c;

        let mut a: i32 = 1;
        let mut b: i32 = 1;
        let n = n as usize;

        if n <= 1 {
            return 1;
        }

        for _ in 2..=n { 
            c = a + b;
            a = b;
            b = c;
        }

        b
    }
}


fn main() {
    let ans = Solution::climb_stairs(44);

    println!("{ans}");
}
