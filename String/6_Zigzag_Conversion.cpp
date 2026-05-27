#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: If there's only 1 row, or the string is shorter than the rows,
        // the zigzag pattern is just the string itself.
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create a vector of strings to hold the characters for each row
        std::vector<std::string> rows(std::min(numRows, static_cast<int>(s.length())));
        
        int currentRow = 0;
        bool goingDown = false;

        // Iterate through each character in the string
        for (char c : s) {
            rows[currentRow] += c;

            // If we are at the top or bottom row, change the direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move up or down based on the direction
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};