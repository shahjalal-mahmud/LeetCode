#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> allTrees;

        // Base case: if start > end, there are no nodes to form a tree.
        // We return a vector containing nullptr to represent an empty child.
        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }

        // Iterate through each number to make it the root
        for (int i = start; i <= end; i++) {
            // 1. Generate all possible left subtrees
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);

            // 2. Generate all possible right subtrees
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);

            // 3. Connect the root 'i' with every combination of left and right subtrees
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }
        return allTrees;
    }
};