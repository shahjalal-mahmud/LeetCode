#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Placeholder for the start
        ListNode* curr = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Extract values, default to 0 if list is exhausted
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            
            int sum = carry + x + y;
            carry = sum / 10; // New carry for next iteration
            
            // Create next node with the single digit result
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Move to next nodes in input lists
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; // Clean up the dummy node memory
        return result;
    }
};