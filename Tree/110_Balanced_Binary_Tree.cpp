#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If checkHeight returns -1, the tree is unbalanced
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) return 0;

        // 1. Check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;

        // 2. Check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;

        // 3. Check current node balance
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // 4. Return actual height to parent call
        return 1 + max(leftHeight, rightHeight);
    }
};