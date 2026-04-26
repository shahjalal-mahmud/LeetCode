#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int count = 0;
        if(root == NULL) return count;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            count++;
        }
        return count;
    }
};