#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Handle empty list or single-node list
        if (!head) return nullptr;

        ListNode* current = head;

        // Traverse until the end of the list
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Found a duplicate: bypass the next node
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; // Free memory of the removed node
            } else {
                // No duplicate: move to the next distinct element
                current = current->next;
            }
        }

        return head;
    }
};