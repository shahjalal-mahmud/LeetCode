#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Start k at 1 because the first element is always unique
        int k = 1; 
        
        // Start i at 1 to compare it with the element at i-1
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the previous one, it's unique!
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Move the unique element to the 'k' position
                k++;               // Increment the count of unique elements
            }
        }
        
        return k;
    }
};