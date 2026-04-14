#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            // XOR each number with the result
            result ^= num;
        }
        return result;
    }
};