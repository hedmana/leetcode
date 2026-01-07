#include <iostream>
#include <vector>
#include <algorithm>

namespace {
    using namespace std;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if (intervals.empty()) {
            return mergedIntervals;
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        mergedIntervals.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= mergedIntervals.back()[1]) {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            } else {
                mergedIntervals.push_back(intervals[i]);
            }
        }

        return mergedIntervals;
    }

};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {0, 3}, {8, 10}, {15, 18}};
    vector<vector<int>> answer = solution.merge(intervals);
    for (auto& interval : answer) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
    return 0;

}