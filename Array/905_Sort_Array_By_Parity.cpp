#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            // Case 1: left is odd and right is even -> Swap
            if (nums[left] % 2 > nums[right] % 2) {
                swap(nums[left], nums[right]);
            }
            
            // Case 2: left is already even -> Move forward
            if (nums[left] % 2 == 0) left++;
            
            // Case 3: right is already odd -> Move backward
            if (nums[right] % 2 != 0) right--;
        }
        
        return nums;
    }
};