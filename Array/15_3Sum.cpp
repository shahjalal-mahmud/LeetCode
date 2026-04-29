#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // 1. Sort the input array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // Optimization: If the smallest number is > 0, sum can't be 0
            if (nums[i] > 0) break;

            // 2. Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // 3. Skip duplicate values for the second and third elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Need a bigger sum
                } 
                else {
                    right--; // Need a smaller sum
                }
            }
        }
        return result;
    }
};