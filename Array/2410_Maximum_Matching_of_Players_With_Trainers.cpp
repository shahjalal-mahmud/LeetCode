#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // Step 1: Sort both arrays
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int p_ptr = 0; // Pointer for players
        int t_ptr = 0; // Pointer for trainers
        int match_count = 0;
        
        // Step 2: Traverse through both arrays
        while (p_ptr < players.size() && t_ptr < trainers.size()) {
            // If the trainer's capacity is enough for the player's ability
            if (players[p_ptr] <= trainers[t_ptr]) {
                match_count++;
                p_ptr++; // Move to the next player
            }
            // Always move to the next trainer because the current trainer 
            // is now either used or unable to match any further players.
            t_ptr++;
        }
        
        return match_count;
    }
};