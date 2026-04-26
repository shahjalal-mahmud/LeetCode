#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        // If left is NULL, we must traverse the right subtree
        if (!root->left) return 1 + minDepth(root->right);
        
        // If right is NULL, we must traverse the left subtree
        if (!root->right) return 1 + minDepth(root->left);
        
        // If both exist, take the minimum of the two
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1}); // Node and its current depth
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            // The moment we find a leaf node, return the depth
            if (!node->left && !node->right) {
                return depth;
            }
            
            if (node->left) q.push({node->left, depth + 1});
            if (node->right) q.push({node->right, depth + 1});
        }
        return 0;
    }
};