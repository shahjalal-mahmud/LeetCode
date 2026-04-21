#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Initialize two pointers
        ListNode *slow = head;
        ListNode *fast = head;

        // Traverse the list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Moves 1 step
            fast = fast->next->next;    // Moves 2 steps

            // If they meet, a cycle exists
            if (slow == fast) {
                return true;
            }
        }

        // If fast reaches the end, no cycle
        return false;
    }
};