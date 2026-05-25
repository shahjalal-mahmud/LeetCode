#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> st;
        
        // Step 1: Find the next greater element for all items in nums2
        for (int num : nums2) {
            // While stack is not empty and current num is greater than the stack's top
            while (!st.empty() && num > st.top()) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num); // Push current element onto the stack
        }
        
        // Step 2: Build the result for nums1 using the map
        std::vector<int> ans;
        ans.reserve(nums1.size());
        for (int num : nums1) {
            if (next_greater.count(num)) {
                ans.push_back(next_greater[num]);
            } else {
                ans.push_back(-1); // No greater element found to its right
            }
        }
        
        return ans;
    }
};