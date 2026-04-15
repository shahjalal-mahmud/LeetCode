#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. Check if the current number is within our k-sized window
            if (window.find(nums[i]) != window.end()) {
                return true;
            }
            
            // 2. Add current number to the window
            window.insert(nums[i]);
            
            // 3. If window size exceeds k, remove the oldest element
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};