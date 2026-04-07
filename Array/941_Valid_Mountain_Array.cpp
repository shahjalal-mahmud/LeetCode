#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;

        // 1. Climb Up
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // 2. Check if the peak is valid
        // The peak cannot be the first element (i == 0) 
        // or the last element (i == n - 1)
        if (i == 0 || i == n - 1) {
            return false;
        }

        // 3. Climb Down
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        // 4. Did we reach the end?
        return i == n - 1;
    }
};