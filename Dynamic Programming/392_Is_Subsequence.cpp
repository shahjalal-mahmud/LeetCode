#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ptr = 0;
        int t_ptr = 0;

        // Iterate through t while we still have characters left in both strings
        while (s_ptr < s.length() && t_ptr < t.length()) {
            // If characters match, move the s pointer to the next character we need
            if (s[s_ptr] == t[t_ptr]) {
                s_ptr++;
            }
            // Always move the t pointer forward
            t_ptr++;
        }

        // If s_ptr reached the end of s, it means all characters were found in order
        return s_ptr == s.length();
    }
};