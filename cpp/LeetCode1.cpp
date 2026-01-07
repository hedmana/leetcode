#include <iostream>
#include <map>
#include <vector>

namespace {
    using namespace std;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        map<int, int> hashTable = {};

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (!(hashTable.find(diff) == hashTable.end())) {
                return {hashTable[diff], i};
            }

            hashTable[nums[i]] = i;
        }
        
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);

    cout << "Result: { ";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << "}" << endl;

    return 0;
}