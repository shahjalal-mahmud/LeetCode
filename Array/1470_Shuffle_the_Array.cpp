#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        
        for (int i = 0; i < n; i++) {
            // The x elements go to even indices: 0, 2, 4...
            ans[2 * i] = nums[i];
            
            // The y elements go to odd indices: 1, 3, 5...
            // Note that the y elements start at nums[n]
            ans[2 * i + 1] = nums[i + n];
        }
        
        return ans;
    }
};