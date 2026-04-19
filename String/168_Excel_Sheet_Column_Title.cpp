#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Adjust to 0-indexed: A becomes 0, B becomes 1... Z becomes 25
            columnNumber--; 
            
            // Get the current character by finding the remainder
            char c = 'A' + (columnNumber % 26);
            result += c;
            
            // Move to the next "digit" in base-26
            columnNumber /= 26;
        }
        
        // Since we appended characters from right to left, reverse the string
        reverse(result.begin(), result.end());
        
        return result;
    }
};