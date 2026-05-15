#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];
        
        // If there are only 2 steps, we can just pick the cheaper one to jump to the top
        if (n == 2) return min(first, second);
        
        for (int i = 2; i < n; i++) {
            // Current minimum cost to step 'i' is its own cost plus 
            // the minimum cost of reaching one of the two previous steps
            int current = cost[i] + min(first, second);
            
            // Shift our trackers forward for the next iteration
            first = second;
            second = current;
        }
        
        // To reach the top floor, we take the minimum of the last two steps
        return min(first, second);
    }
};