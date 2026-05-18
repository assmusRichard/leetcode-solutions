// Leetcode 3 Longest Substring Without Repeating Characters

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/*
Given a string s, find the length of the longest without duplicate characters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            std::vector<int> lastIndex(256, -1);
            int left = 0;
            int best = 0;

            for(int right = 0; right < s.size(); right++) {
                char c = s[right];

                if(lastIndex[c] >= left) left = lastIndex[c] + 1;

                lastIndex[c] = right;
                int length = right - left + 1;
                best = std::max(length, best);
            }

            return best; 
        }
};

int main() {
    std::string s = "pwwkew";
    Solution sol;
    int n = sol.lengthOfLongestSubstring(s);

    std::cout << n << std::endl;
}

