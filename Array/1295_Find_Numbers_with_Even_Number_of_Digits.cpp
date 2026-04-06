#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int count = 0;
            int temp = nums[i];
            
            while(temp > 0) {
                temp /= 10;
                count++;
            }
            
            if(count % 2 == 0) {
                result++;
            }
        }
        
        return result;
    }
};