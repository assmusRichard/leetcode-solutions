#include <vector>
#include <climits>

// Leetcode 4 Median of Two Sorted Arrays

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

class Solution {
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
            if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1); 

            int m = nums1.size();
            int n = nums2.size();

            int halfLen = (m + n) / 2;

            int left = 0; 
            int right = m;

            while(left <= right) {
                int i = left + (right - left) / 2;  //partition nums1
                int j =  halfLen - i;               //partition nums2

                int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
                int nums1RightMin = (i == m) ? INT_MAX : nums1[i];

                int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
                int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

                if(nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                    if((m + n) % 2 == 0) {
                        return (std::max(nums1LeftMax, nums2LeftMax) + std::min(nums1RightMin, nums2RightMin)) / 2.0;
                    } else {
                        return std::min(nums1RightMin, nums2RightMin);
                    }
                } else if(nums1LeftMax > nums2RightMin) {
                    right = i - 1;
                } else {
                    left = i + 1;
                }
            }
            return 0;
        }
};

#include <iostream>
int main() {
    std::vector<int> nums1 = {1,2};
    std::vector<int> nums2 = {3,4};

    Solution sol;

    double median = sol.findMedianSortedArrays(nums1, nums2);

    std::cout << median << std::endl;

    return 0;
}