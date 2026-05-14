#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child_i = 0;
        int cookie_j = 0;

        // Iterate through cookies and children
        while (child_i < g.size() && cookie_j < s.size()) {
            // If the current cookie can satisfy the current child
            if (s[cookie_j] >= g[child_i]) {
                child_i++; // Move to the next child
            }
            // Always move to the next cookie
            cookie_j++;
        }

        return child_i;
    }
};