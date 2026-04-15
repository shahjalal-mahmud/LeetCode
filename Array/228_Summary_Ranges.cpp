#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            
            // Keep moving i forward if the next element is consecutive
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            
            // i is now at the end of the current range
            if (start != nums[i]) {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            } else {
                result.push_back(to_string(start));
            }
        }
        
        return result;
    }
};