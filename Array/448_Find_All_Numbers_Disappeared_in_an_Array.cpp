#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        
        // Step 1: Mark visited indices
        for (int i = 0; i < nums.size(); i++) {
            // Use abs() because the value at this index might have been made negative already
            int index = abs(nums[i]) - 1; 
            
            // If the value at that index is positive, flip it to negative
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        // Step 2: Check for indices that remained positive
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                // If it's positive, it means the number (index + 1) was never seen
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};