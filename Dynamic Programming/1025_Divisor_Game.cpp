#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool divisorGame(int n) {
        // Alice wins if the initial number is even, 
        // because she can always force Bob into a losing odd-number position.
        return n % 2 == 0;
    }
};