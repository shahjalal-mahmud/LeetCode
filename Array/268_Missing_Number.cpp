#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Use the formula for the sum of the first n numbers: n*(n+1)/2
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size(); // Start with n
        for (int i = 0; i < nums.size(); i++) {
            res ^= i ^ nums[i]; // XOR index and value
        }
        return res;
    }
};