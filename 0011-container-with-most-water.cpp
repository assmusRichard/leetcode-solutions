// Leetcode 11 Container With Most Water

// https://leetcode.com/problems/container-with-most-water/description/

/*
You are given an integer array height of length n. There are n vertical lines drawn 
such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        int maxArea(std::vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int maxWater = 0;
            int currWater;

            while(left < right) {
                currWater = (right - left) * std::min(height[left], height[right]);
                maxWater = std::max(currWater, maxWater);

                if(height[left] <= height[right]) {
                    left++;
                } else {
                    right--;
                }
            }

            return maxWater;
        }
};

int main() {
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    int maxArea = sol.maxArea(height);

    std::cout << "max area: " << maxArea << std::endl;
}