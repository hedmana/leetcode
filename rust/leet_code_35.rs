struct Solution;

impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut low = 0;
        let mut high = nums.len();

        while low < high {
            let mid = low + (high - low) / 2;
            let val = nums[mid];

            if val < target {
                low = mid + 1; 
            } else {
                high = mid;
            } 
        } 
        low as i32    
    }
}


fn main() {
    let nums = [1, 1, 3, 3 ,4];
    let target = 2;
    let ans = Solution::search_insert(nums.to_vec(), target);
    println!("{ans}");
}
