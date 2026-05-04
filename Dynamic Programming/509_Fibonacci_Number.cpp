#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        // Base cases
        if (n <= 1) {
            return n;
        }

        // Initialize the first two Fibonacci numbers
        int prev2 = 0; // F(0)
        int prev1 = 1; // F(1)
        int current = 0;

        // Iterate from 2 up to n
        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2; // F(n) = F(n-1) + F(n-2)
            
            // Update pointers for the next iteration
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};