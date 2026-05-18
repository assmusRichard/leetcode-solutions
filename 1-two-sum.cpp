#include <vector>
#include <unordered_map>
#include <iostream>

// Leetcode 1 Two Sum

// https://leetcode.com/problems/two-sum/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> seen;

            for(int i = 0; i < nums.size(); i++) {
                int complement = target - nums[i];
                if(seen.find(complement) != seen.end()) return {seen[complement], i};
                seen[nums[i]] = i;
            }
            return {};
        }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    std::vector<int> result = sol.twoSum(nums, target);
    for(int x : result) std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
