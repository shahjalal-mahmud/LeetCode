#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Split string s into individual words
        stringstream ss(s);
        string word;
        vector<string> words;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        // If the number of characters doesn't match the number of words, 
        // a bijective mapping is impossible.
        if (pattern.length() != words.size()) {
            return false;
        }
        
        // Hash maps to store the bidirectional mappings
        unordered_map<char, string> char_to_word;
        unordered_map<string, char> word_to_char;
        
        for (int i = 0; i < pattern.length(); ++i) {
            char c = pattern[i];
            string w = words[i];
            
            // Check character to word mapping
            if (char_to_word.count(c) && char_to_word[c] != w) {
                return false;
            }
            
            // Check word to character mapping
            if (word_to_char.count(w) && word_to_char[w] != c) {
                return false;
            }
            
            // Establish the bidirectional mapping
            char_to_word[c] = w;
            word_to_char[w] = c;
        }
        
        return true;
    }
};