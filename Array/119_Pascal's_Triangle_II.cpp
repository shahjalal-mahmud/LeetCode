#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        
        // We use long long for the calculation to prevent overflow 
        // before the final division.
        long long currentVal = 1;
        
        for (int k = 1; k < rowIndex; k++) {
            // Using the formula: next = prev * (n - k + 1) / k
            currentVal = currentVal * (rowIndex - k + 1) / k;
            row[k] = (int)currentVal;
        }
        
        return row;
    }
};