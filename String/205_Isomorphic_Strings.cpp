#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Since the strings consist of ASCII characters, 
        // we can use arrays of size 256 for O(1) access.
        int mapStoT[256] = {0};
        int mapTtoS[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            char charS = s[i];
            char charT = t[i];

            // Check if there is a conflicting mapping from S to T
            if (mapStoT[charS] != 0 && mapStoT[charS] != charT) {
                return false;
            }
            // Check if there is a conflicting mapping from T to S
            if (mapTtoS[charT] != 0 && mapTtoS[charT] != charS) {
                return false;
            }

            // Establish the mapping
            mapStoT[charS] = charT;
            mapTtoS[charT] = charS;
        }

        return true;
    }
};