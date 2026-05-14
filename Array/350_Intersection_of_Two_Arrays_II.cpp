#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Optimization: Ensure nums1 is the smaller array to save space
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        std::unordered_map<int, int> counts;
        for (int num : nums1) {
            counts[num]++;
        }

        std::vector<int> result;
        for (int num : nums2) {
            if (counts.find(num) != counts.end() && counts[num] > 0) {
                result.push_back(num);
                counts[num]--;
            }
        }
        return result;
    }
};