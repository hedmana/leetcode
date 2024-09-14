#include <iostream>
#include <map>
#include <vector>
#include <string>

namespace {
    using namespace std;
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for (int i = 1; i < n; i++) {
            output[i] = output[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *=  right;
            right *= nums[i];
        }
        return output;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> answer = solution.productExceptSelf(nums);

    cout << "Length of answer: " << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}