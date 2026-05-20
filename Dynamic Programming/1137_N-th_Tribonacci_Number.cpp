#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        // Base cases handled directly
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        // Track the last three values: T_0, T_1, T_2
        int t0 = 0, t1 = 1, t2 = 1;
        
        // Calculate iteratively up to n
        for (int i = 3; i <= n; ++i) {
            int next_t = t0 + t1 + t2;
            
            // Shift variables forward for the next iteration
            t0 = t1;
            t1 = t2;
            t2 = next_t;
        }
        
        return t2;
    }
};