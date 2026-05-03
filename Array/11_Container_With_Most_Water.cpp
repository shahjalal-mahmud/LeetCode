#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Calculate current width
            int width = right - left;
            
            // Calculate current area using the limiting (shorter) height
            int current_height = std::min(height[left], height[right]);
            int current_area = width * current_height;
            
            // Update the maximum area found so far
            max_water = std::max(max_water, current_area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};