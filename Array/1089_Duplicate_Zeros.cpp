#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                temp.push_back(0);
                temp.push_back(0);
            } else {
                temp.push_back(arr[i]);
            }
            
            // Stop adding if we've filled up the original size
            if (temp.size() >= n) break;
        }

        // Copy the first 'n' elements of temp back into the original arr
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};