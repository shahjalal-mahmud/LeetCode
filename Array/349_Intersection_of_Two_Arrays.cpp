#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Store unique elements of nums1 in a hash set
        unordered_set<int> set1(nums1.begin(), nums1.end());
        vector<int> result;
        
        // Step 2: Iterate through nums2 and check for existence in set1
        for (int num : nums2) {
            if (set1.count(num)) {
                result.push_back(num);
                // Step 3: Remove from set to handle uniqueness in the output
                set1.erase(num);
            }
        }
        
        return result;
    }
};