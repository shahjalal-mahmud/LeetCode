#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            
            // Root: Process the current node
            result.push_back(curr->val);
            
            // Right child is pushed first so Left child is processed first
            if (curr->right) {
                st.push(curr->right);
            }
            if (curr->left) {
                st.push(curr->left);
            }
        }
        
        return result;
    }
};

class Solution2 {
public:
    void traverse(TreeNode* node, vector<int>& result) {
        if (!node) return;
        
        result.push_back(node->val);  // Root
        traverse(node->left, result);  // Left
        traverse(node->right, result); // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};