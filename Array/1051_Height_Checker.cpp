#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // 1. Create a copy of the original array
        vector<int> expected = heights;
        
        // 2. Sort the copy to get the correct non-decreasing order
        sort(expected.begin(), expected.end());
        
        int count = 0;
        
        // 3. Compare the original heights with the expected heights
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                count++;
            }
        }
        
        return count;
    }
};