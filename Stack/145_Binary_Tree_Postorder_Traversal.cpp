#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> traversalStack;
        traversalStack.push(root);
        
        while (!traversalStack.empty()) {
            TreeNode* curr = traversalStack.top();
            traversalStack.pop();
            
            // Push the current node's value to our result
            result.push_back(curr->val);
            
            // Push left first so that right is processed first (Root -> Right -> Left)
            if (curr->left != nullptr) {
                traversalStack.push(curr->left);
            }
            if (curr->right != nullptr) {
                traversalStack.push(curr->right);
            }
        }
        
        // Reverse the entire result to get Left -> Right -> Root
        reverse(result.begin(), result.end());
        
        return result;
    }
};