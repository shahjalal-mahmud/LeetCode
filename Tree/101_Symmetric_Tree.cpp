#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
    bool isSymmetric(TreeNode* root){
        if(root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val) return false;
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
};

// Iterative approach using a queue
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        // Queue to store pairs of nodes to compare
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();

            // If both are null, this branch is symmetric so far
            if (t1 == nullptr && t2 == nullptr) continue;
            
            // If one is null or values differ, it's not symmetric
            if (t1 == nullptr || t2 == nullptr) return false;
            if (t1->val != t2->val) return false;

            // Push children in "mirror pairs"
            // Outer pair: Left of T1 and Right of T2
            q.push(t1->left);
            q.push(t2->right);
            
            // Inner pair: Right of T1 and Left of T2
            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};