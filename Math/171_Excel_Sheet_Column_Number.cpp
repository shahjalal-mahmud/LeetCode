#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0; // Use long long to prevent overflow during intermediate steps
        
        for (char c : columnTitle) {
            // Convert char to its 1-26 value
            int d = c - 'A' + 1;
            
            // Shift existing value left (base 26) and add the new digit
            result = result * 26 + d;
        }
        
        return (int)result;
    }
};