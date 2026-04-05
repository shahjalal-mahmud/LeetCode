#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Initialize a 2D vector with numRows rows
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            // Create a row of size (i + 1), filled with 1s
            // This automatically handles the first and last elements
            vector<int> row(i + 1, 1);

            // Fill the interior elements (from index 1 to i-1)
            for (int j = 1; j < i; j++) {
                // The value is the sum of the two elements directly above it
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // Add the completed row to our triangle
            triangle.push_back(row);
        }

        return triangle;
    }
};