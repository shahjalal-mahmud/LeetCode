#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // This will track the position for the next "good" element
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is NOT the one we want to remove
            if (nums[i] != val) {
                // Move it to the front of the array at index 'k'
                nums[k] = nums[i];
                // Increment k to prepare for the next good element
                k++;
            }
        }
        
        // k represents the count of elements not equal to val
        return k;
    }
};