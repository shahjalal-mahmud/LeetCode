#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    // --- METHOD 1: RECURSIVE ---
    // Time: O(n), Space: O(n)
    void recursiveHelper(TreeNode* node, vector<int>& result) {
        if (!node) return;
        
        recursiveHelper(node->left, result);  // Left
        result.push_back(node->val);          // Root
        recursiveHelper(node->right, result); // Right
    }

    vector<int> inorderRecursive(TreeNode* root) {
        vector<int> result;
        recursiveHelper(root, result);
        return result;
    }

    // --- METHOD 2: ITERATIVE (Using Stack) ---
    // Time: O(n), Space: O(n)
    vector<int> inorderIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            // 1. Go as far left as possible
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            // 2. Process the node
            curr = s.top();
            s.pop();
            result.push_back(curr->val);

            // 3. Move to the right subtree
            curr = curr->right;
        }
        return result;
    }
};

// --- Testing the code ---
int main() {
    /* Tree Structure:
             1
              \
               2
              /
             3
    */
    TreeNode* three = new TreeNode(3);
    TreeNode* two = new TreeNode(2, three, nullptr);
    TreeNode* root = new TreeNode(1, nullptr, two);

    Solution sol;
    
    vector<int> recResult = sol.inorderRecursive(root);
    vector<int> iterResult = sol.inorderIterative(root);

    cout << "Recursive: ";
    for (int x : recResult) cout << x << " "; // Output: 1 3 2
    
    cout << "\nIterative: ";
    for (int x : iterResult) cout << x << " "; // Output: 1 3 2
    cout << endl;

    return 0;
}