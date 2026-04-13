#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store: Key = value in nums, Value = index of that value
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in our map
            if (numMap.find(complement) != numMap.end()) {
                // Return the index of the complement and the current index
                return {numMap[complement], i};
            }
            
            // Otherwise, add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        // Return empty vector if no solution is found (though constraints guarantee one)
        return {};
    }
};