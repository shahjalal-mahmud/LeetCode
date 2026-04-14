#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // If count is 0, we establish a new candidate
            if (count == 0) {
                candidate = num;
            }
            
            // Increment count if we see the candidate again,
            // otherwise decrement (the "voting"/cancellation step)
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};