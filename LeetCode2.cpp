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
        if (s.length() == 0) {
            return 0;
        }

        if (s.length() == 1) {
            return 1; 
        } 

        int longest = 0; 
        vector<bool> visited(256, false);

        // sliding window pointers
        int left = 0, right = 0;
        while (right < s.length()) {

            while (visited[s[right]] == true) {
                visited[s[left]] = false;
                left++;
            }

            visited[s[right]] = true;
            longest = max(longest, (right - left + 1));
            right++;
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