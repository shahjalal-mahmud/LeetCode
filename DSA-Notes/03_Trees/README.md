# 🌳 Trees - DSA Notes

> **Master Index for all Tree-related problems and concepts**

---

## 📊 Progress Overview

| Topic                                      | Problems Solved | Last Updated |
| ------------------------------------------ | --------------- | ------------ |
| [Tree Traversals](#-1-tree-traversals)     | 0 / 5+          | -            |
| [Tree Comparison](#-2-tree-comparison)     | 1 / 8+          | 25 Apr 2026  |
| [BST Properties](#-3-bst-properties)       | 0 / 6+          | -            |
| [LCA & Paths](#-4-lca--paths)              | 0 / 5+          | -            |
| [Tree Construction](#-5-tree-construction) | 0 / 5+          | -            |

**Total Progress:** 🟢🟢⚪⚪⚪ (1 problem solved)

---

## 📁 1. Tree Traversals

> **File:** [`01_Tree_Traversals.md`](./01_Tree_Traversals.md)
> **Focus:** Inorder, Preorder, Postorder, Level Order, Zigzag, etc.

| Problem                           | LeetCode                                                                       | Difficulty | Key Technique           | Status  |
| --------------------------------- | ------------------------------------------------------------------------------ | ---------- | ----------------------- | ------- |
| Binary Tree Inorder Traversal     | [94](https://leetcode.com/problems/binary-tree-inorder-traversal/)             | Easy       | Recursive/Iterative DFS | ⬜ Todo |
| Binary Tree Preorder Traversal    | [144](https://leetcode.com/problems/binary-tree-preorder-traversal/)           | Easy       | Recursive/Iterative DFS | ⬜ Todo |
| Binary Tree Postorder Traversal   | [145](https://leetcode.com/problems/binary-tree-postorder-traversal/)          | Easy       | Recursive/Iterative DFS | ⬜ Todo |
| Binary Tree Level Order Traversal | [102](https://leetcode.com/problems/binary-tree-level-order-traversal/)        | Medium     | BFS with Queue          | ⬜ Todo |
| Zigzag Level Order Traversal      | [103](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) | Medium     | BFS + Reverse Flag      | ⬜ Todo |
| Binary Tree Right Side View       | [199](https://leetcode.com/problems/binary-tree-right-side-view/)              | Medium     | BFS (last node)         | ⬜ Todo |

**Key Patterns to Master:**

- Recursive vs Iterative approaches
- Using stack for DFS traversal
- Using queue for level order
- Morris traversal (O(1) space)

---

## 📁 2. Tree Comparison

> **File:** [`02_Tree_Comparison.md`](./02_Tree_Comparison.md)
> **Focus:** Comparing two trees, symmetry, subtree checking

| Problem                                      | LeetCode                                                                            | Difficulty | Key Technique            | Status  |
| -------------------------------------------- | ----------------------------------------------------------------------------------- | ---------- | ------------------------ | ------- |
| Same Tree                                    | [100](https://leetcode.com/problems/same-tree/description/)                         | Easy       | DFS/BFS Comparison       | ✅ Done |
| Symmetric Tree                               | [101](https://leetcode.com/problems/symmetric-tree/)                                | Easy       | Mirror Comparison        | ⬜ Todo |
| Subtree of Another Tree                      | [572](https://leetcode.com/problems/subtree-of-another-tree/)                       | Easy       | SameTree as Helper       | ⬜ Todo |
| Flip Equivalent Binary Trees                 | [951](https://leetcode.com/problems/flip-equivalent-binary-trees/)                  | Medium     | Recursive with Flip      | ⬜ Todo |
| Leaf-Similar Trees                           | [872](https://leetcode.com/problems/leaf-similar-trees/)                            | Easy       | Leaf Sequence Generation | ⬜ Todo |
| Check If Two Expression Trees are Equivalent | [1612](https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent/) | Medium     | Tree Hashing             | ⬜ Todo |
| Merge Two Binary Trees                       | [617](https://leetcode.com/problems/merge-two-binary-trees/)                        | Easy       | Simultaneous Traversal   | ⬜ Todo |
| Cousins in Binary Tree                       | [993](https://leetcode.com/problems/cousins-in-binary-tree/)                        | Easy       | BFS with Parent Tracking | ⬜ Todo |

**Key Patterns to Master:**

- Tree equality pattern (null checks + recursion)
- Mirror comparison (swap left/right)
- Using one tree as reference to check another
- Hash-based comparison for large trees

---

## 📁 3. BST Properties

> **File:** [`03_BST_Properties.md`](./03_BST_Properties.md)
> **Focus:** BST validation, search, insertion, deletion, properties

| Problem                       | LeetCode                                                                             | Difficulty | Key Technique                     | Status  |
| ----------------------------- | ------------------------------------------------------------------------------------ | ---------- | --------------------------------- | ------- |
| Validate Binary Search Tree   | [98](https://leetcode.com/problems/validate-binary-search-tree/)                     | Medium     | Inorder Traversal / Min-Max Range | ⬜ Todo |
| Search in a BST               | [700](https://leetcode.com/problems/search-in-a-binary-search-tree/)                 | Easy       | BST Property                      | ⬜ Todo |
| Insert into a BST             | [701](https://leetcode.com/problems/insert-into-a-binary-search-tree/)               | Medium     | Recursive Insertion               | ⬜ Todo |
| Delete Node in a BST          | [450](https://leetcode.com/problems/delete-node-in-a-bst/)                           | Medium     | Find Successor/Predecessor        | ⬜ Todo |
| Kth Smallest Element in BST   | [230](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)                  | Medium     | Inorder Traversal                 | ⬜ Todo |
| Lowest Common Ancestor in BST | [235](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | Easy       | BST Property (value comparison)   | ⬜ Todo |
| Convert Sorted Array to BST   | [108](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)     | Easy       | Recursive Mid-point               | ⬜ Todo |
| Two Sum IV - Input is BST     | [653](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)                      | Easy       | Inorder + Two Pointer / HashSet   | ⬜ Todo |

**Key Patterns to Master:**

- Inorder traversal gives sorted order
- Min-max range validation
- BST search property: left < root < right
- Finding successor/predecessor

---

## 📁 4. LCA & Paths

> **File:** [`04_LCA_and_Paths.md`](./04_LCA_and_Paths.md)
> **Focus:** Lowest Common Ancestor, root-to-node paths, path sums

| Problem                              | LeetCode                                                                      | Difficulty | Key Technique               | Status  |
| ------------------------------------ | ----------------------------------------------------------------------------- | ---------- | --------------------------- | ------- |
| Lowest Common Ancestor (Binary Tree) | [236](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | Medium     | Postorder Recursion         | ⬜ Todo |
| Path Sum                             | [112](https://leetcode.com/problems/path-sum/)                                | Easy       | DFS with Target Subtraction | ⬜ Todo |
| Path Sum II                          | [113](https://leetcode.com/problems/path-sum-ii/)                             | Medium     | Backtracking                | ⬜ Todo |
| Path Sum III                         | [437](https://leetcode.com/problems/path-sum-iii/)                            | Medium     | Prefix Sum + HashMap        | ⬜ Todo |
| Binary Tree Paths                    | [257](https://leetcode.com/problems/binary-tree-paths/)                       | Easy       | DFS with String Building    | ⬜ Todo |
| Sum Root to Leaf Numbers             | [129](https://leetcode.com/problems/sum-root-to-leaf-numbers/)                | Medium     | DFS with Path Sum           | ⬜ Todo |
| Maximum Path Sum                     | [124](https://leetcode.com/problems/binary-tree-maximum-path-sum/)            | Hard       | Postorder + Global Max      | ⬜ Todo |
| Diameter of Binary Tree              | [543](https://leetcode.com/problems/diameter-of-binary-tree/)                 | Easy       | Postorder (Height + Max)    | ⬜ Todo |

**Key Patterns to Master:**

- LCA pattern: return node when found, null otherwise
- Path tracking with backtracking
- Postorder traversal for bottom-up calculations
- Prefix sum optimization for path sums

---

## 📁 5. Tree Construction

> **File:** [`05_Tree_Construction.md`](./05_Tree_Construction.md)
> **Focus:** Building trees from traversals, serialization/deserialization

| Problem                                  | LeetCode                                                                                          | Difficulty | Key Technique                 | Status  |
| ---------------------------------------- | ------------------------------------------------------------------------------------------------- | ---------- | ----------------------------- | ------- |
| Construct Tree from Inorder & Preorder   | [105](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)   | Medium     | Recursive with HashMap Index  | ⬜ Todo |
| Construct Tree from Inorder & Postorder  | [106](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)  | Medium     | Recursive with HashMap Index  | ⬜ Todo |
| Construct Tree from Preorder & Postorder | [889](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) | Medium     | Recursive with Index Tracking | ⬜ Todo |
| Serialize and Deserialize Binary Tree    | [297](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)                       | Hard       | BFS/DFS with Null Markers     | ⬜ Todo |
| Serialize and Deserialize BST            | [449](https://leetcode.com/problems/serialize-and-deserialize-bst/)                               | Medium     | Preorder (smaller encoding)   | ⬜ Todo |
| Binary Tree from String                  | [536](https://leetcode.com/problems/construct-binary-tree-from-string/)                           | Medium     | Stack / Recursive Parsing     | ⬜ Todo |
| Recover Binary Search Tree               | [99](https://leetcode.com/problems/recover-binary-search-tree/)                                   | Medium     | Inorder + Swapped Nodes       | ⬜ Todo |

**Key Patterns to Master:**

- First element in preorder = root
- Last element in postorder = root
- Using inorder to identify left/right subtrees
- HashMap for O(1) index lookups
- Serialization with delimiters and null markers

---

## 🎯 Quick Reference

### Common Tree Terminologies

| Term          | Meaning                                                   |
| ------------- | --------------------------------------------------------- |
| Height        | Number of edges from root to deepest leaf                 |
| Depth         | Number of edges from root to a node                       |
| Balanced Tree | Height difference ≤ 1 for all nodes                       |
| Skewed Tree   | All nodes on one side (like a linked list)                |
| Complete Tree | All levels filled except possibly last                    |
| Full Tree     | Every node has 0 or 2 children                            |
| Perfect Tree  | All internal nodes have 2 children & leaves at same level |

### Complexity Cheat Sheet

| Operation | Balanced BST | Skewed Tree |
| --------- | ------------ | ----------- |
| Search    | O(log n)     | O(n)        |
| Insert    | O(log n)     | O(n)        |
| Delete    | O(log n)     | O(n)        |
| Traversal | O(n)         | O(n)        |

### Recursive Template for Tree Problems

```cpp
void solve(TreeNode* root) {
    // 1. Base case
    if(!root) return;

    // 2. Process current node (Preorder)

    // 3. Recurse on left
    solve(root->left);

    // 4. Process current node (Inorder)

    // 5. Recurse on right
    solve(root->right);

    // 6. Process current node (Postorder)
}
```

---

## 🔗 Useful Resources

- [LeetCode Tree Problem List](https://leetcode.com/tag/tree/)
- [Binary Tree Visualizer](https://www.cs.usfca.edu/~galles/visualization/BST.html)
- [NeetCode Tree Playlist](https://www.youtube.com/watch?v=OnSn2XEQ4MY&list=PLot-Xpze53ldg4pN6PfzoJYcKs0b5DFgC)

---
