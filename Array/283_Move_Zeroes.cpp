#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // lastNonZeroFoundAt points to the index where the next 
        // non-zero element should be moved.
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                // Swap the current non-zero element with the 
                // element at lastNonZeroFoundAt
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};