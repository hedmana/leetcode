#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + skill[i];
        }
        long long result = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            result += count[prefixSum[i] - i];
            count[prefixSum[i] - i]++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> skill = {3,2,5,1,3,4};
    long long result = solution.dividePlayers(skill);
    cout << result << endl;
    return 0;
}