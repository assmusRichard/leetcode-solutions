// Leetcode 5 Longest Palindromic Substring

// https://leetcode.com/problems/longest-palindromic-substring/description/

/*
Given a string s, return the longest palindromic substring in s.
*/

#include <iostream>
#include <string>

class Solution {
    public:
        std::string longestPalindrome(std::string s) {
            if(s.size() == 0) return "";

            int best = 0;
            int start;

            for(int i = 0; i < s.size(); i++) {
                int len1 = expandAroundCenter(s, i, i);
                int len2 = expandAroundCenter(s, i, i + 1);

                int currLength = std::max(len1, len2);

                if(currLength >= best) {
                    best = currLength;
                    start = i - (currLength - 1) / 2;
                }
            }

            return s.substr(start, best);
        }

        int expandAroundCenter(std::string s, int i, int j) {
            while(i >= 0 && j < s.size() && s[i] == s[j]) {
                i--;
                j++;
            }

            return j - i - 1;
        }
};

int main() {
    std::string s = "cbbd";
    Solution sol;
    std::string pSubstring = sol.longestPalindrome(s);

    std::cout << "Longest Palindromic Substring in " << s << ": " << pSubstring << std::endl;

    return 0;
}
