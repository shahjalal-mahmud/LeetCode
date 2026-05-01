#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        // If they have the same length, they meet in the first pass.
        // If they have different lengths, they meet in the second pass.
        while (ptrA != ptrB) {
            // If ptrA reaches the end, switch to headB, else move to next
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            
            // If ptrB reaches the end, switch to headA, else move to next
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        // ptrA will either be the intersection node or nullptr
        return ptrA;
    }
};