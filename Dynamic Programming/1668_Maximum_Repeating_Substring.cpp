#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRepeating(std::string sequence, std::string word) {
        int k = 0;
        std::string repeated_word = word;
        
        // Keep checking if the repeated_word exists in sequence
        // string::npos is returned when the substring is not found
        while (sequence.find(repeated_word) != std::string::npos) {
            k++;
            repeated_word += word; // Add another copy of word for the next check
        }
        
        return k;
    }
};