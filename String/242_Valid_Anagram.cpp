#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths don't match, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Array to store the frequency of each lowercase letter (a-z)
        int count[26] = {0};
        
        // Count frequencies
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; // Increment for string s
            count[t[i] - 'a']--; // Decrement for string t
        }
        
        // If s and t are anagrams, every element in count should be 0
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};