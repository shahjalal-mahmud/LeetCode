#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; // Handle 0 and 1 separately

        int left = 1, right = x / 2; // Square root of x (where x > 1) is never > x/2
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Use long long for the square to prevent overflow
            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid;     // Store the last "rounded down" candidate
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};