#include <iostream>
#include <vector>

namespace {
    using namespace std;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];   
        int currentSum = nums[0];
        for (int i = 1; i < n; i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
        return maxSum;
    }  
};

int main() {
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};     
    int answer = solution.maxSubArray(nums); 
    cout << "Answer: " << answer << endl;
    return 0;

}