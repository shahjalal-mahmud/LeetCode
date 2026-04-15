#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // Unordered set to keep track of seen elements
        std::unordered_set<int> seen;
        
        for (int num : nums) {
            // If num is already in the set, we found a duplicate
            if (seen.find(num) != seen.end()) {
                return true;
            }
            // Insert the current number into the set
            seen.insert(num);
        }
        
        // If we reach the end, all elements are unique
        return false;
    }
};