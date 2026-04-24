#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        // Initialize a vector of size 2 * n
        vector<int> ans(2 * n);
        
        for (int i = 0; i < n; i++) {
            // Fill the first half
            ans[i] = nums[i];
            // Fill the second half at the offset n
            ans[i + n] = nums[i];
        }
        
        return ans;
    }
};