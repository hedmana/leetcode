struct Solution;

impl solution {
    pub fn plus_one(mut digits: vec<i32>) -> vec<i32> {
        for i in (0..digits.len()).rev() {
            if digits[i] < 9 {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(0, 1);
        digits
    }
}


fn main() {
    let ans = Solution::plus_one(vec![1, 2, 9]);

    for n in ans {
        println!("{n}");
    }
}
