#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int last_group = -1; // Tracks the group of the last added word
        
        for (int i = 0; i < words.size(); ++i) {
            // If the current group is different from the last picked group
            if (groups[i] != last_group) {
                result.push_back(words[i]);
                last_group = groups[i]; // Update the last picked group
            }
        }
        
        return result;
    }
};