#include<iostream>
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Iterative BFS (Using Queue)
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Use a queue to store pairs of nodes to compare
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});

        while (!que.empty()) {
            auto [nodeP, nodeQ] = que.front();
            que.pop();

            // 1. Both are null - this branch is identical, continue to next pair
            if (!nodeP && !nodeQ) continue;

            // 2. One is null or values differ - trees are different
            if (!nodeP || !nodeQ || nodeP->val != nodeQ->val) return false;

            // 3. Push children in pairs to ensure we compare the same positions
            que.push({nodeP->left, nodeQ->left});
            que.push({nodeP->right, nodeQ->right});
        }

        return true;
    }
};

// Iterative DFS (Using a Stack)
class Solution3 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while (!st.empty()) {
            auto [nodeP, nodeQ] = st.top();
            st.pop();

            // Check conditions (same logic as BFS)
            if (!nodeP && !nodeQ) continue;
            if (!nodeP || !nodeQ || nodeP->val != nodeQ->val) return false;

            // Push right children first, so left children are processed first (LIFO)
            st.push({nodeP->right, nodeQ->right});
            st.push({nodeP->left, nodeQ->left});
        }

        return true;
    }
};