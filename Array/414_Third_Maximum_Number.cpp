#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Use long long to handle the case where INT_MIN is in the input
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int num : nums) {
            // Skip if the number is already one of our top three (distinct only)
            if (num == first || num == second || num == third) continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        // If third was never updated, return the maximum (first)
        return (third == LLONG_MIN) ? (int)first : (int)third;
    }
};