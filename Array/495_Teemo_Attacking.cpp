#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // If there are no attacks or duration is 0, Ashe is never poisoned
        if (timeSeries.empty() || duration == 0) return 0;
        
        int totalSeconds = 0;
        int n = timeSeries.size();
        
        // Loop through all attacks except the very last one
        for (int i = 0; i < n - 1; ++i) {
            int gap = timeSeries[i + 1] - timeSeries[i];
            
            // We either take the full duration or get cut short by the next attack
            totalSeconds += min(duration, gap);
        }
        
        // The final attack always inflicts the full duration
        totalSeconds += duration;
        
        return totalSeconds;
    }
};