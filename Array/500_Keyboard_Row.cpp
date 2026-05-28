#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Map each character to its respective row on the QWERTY keyboard
        unordered_map<char, int> rowMap;
        
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        
        for (char c : row1) rowMap[c] = 1;
        for (char c : row2) rowMap[c] = 2;
        for (char c : row3) rowMap[c] = 3;
        
        vector<string> result;
        
        for (const string& word : words) {
            if (word.empty()) continue;
            
            // Get the row of the first character (converted to lowercase)
            int targetRow = rowMap[tolower(word[0])];
            bool isValid = true;
            
            // Check if all other characters belong to the same row
            for (char c : word) {
                if (rowMap[tolower(c)] != targetRow) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};