#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        // Initialize vector of size n + 1 with zeros
        vector<int> ans(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // ans[i >> 1] is the result for i/2 which we already computed
            // (i & 1) adds 1 if the current number is odd
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};