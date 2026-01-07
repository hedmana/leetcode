#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> count(k, 0);
        for (int num : arr) {
            count[(num % k + k) % k]++;
        }
        for (int i = 1; i < k; i++) {
            if (count[i] != count[k - i]) {
                return false;
            }
        }
        return count[0] % 2 == 0;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k = 5;
    bool result = solution.canArrange(arr, k);
    cout << result << endl;
    return 0;
}
