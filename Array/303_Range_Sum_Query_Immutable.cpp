#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class NumArray {
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) {
        // Initialize prefixSum with size n + 1
        // prefixSum[i] will store the sum of nums[0...i-1]
        int n = nums.size();
        prefixSum.assign(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // The sum of nums[left...right] is prefixSum[right+1] - prefixSum[left]
        return prefixSum[right + 1] - prefixSum[left];
    }
};