#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // Base case: if the range is invalid, this branch is empty
        if (left > right) {
            return nullptr;
        }

        // Choose the middle element to ensure height balance
        int mid = left + (right - left) / 2;
        
        // Create the root node with the middle value
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};