#include <iostream>
#include <map>
#include <vector>
#include <string>

namespace {
    using namespace std;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {   
        int longest = 0;

        for(int i = 0; i < s.size(); i++) {
            vector<bool> visited(256, false);

            for (int j = i; j < s.size(); j++) {
                if (visited[s[j]] == true) {
                    break;
                } else {
                    longest = max(longest, j - i + 1);
                    visited[s[j]] = true;
                }
            }
        }
        return longest;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";

    cout << "Result: " << solution.lengthOfLongestSubstring(s) << endl;
        
    return 0;
}