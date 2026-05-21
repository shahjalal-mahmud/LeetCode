#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: If the tree is empty, there are no paths at all
        if (root == nullptr) {
            return false;
        }
        
        // Check if we are at a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        
        // Recurse on the left and right subtrees with the updated target sum
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};