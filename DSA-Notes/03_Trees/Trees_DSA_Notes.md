# 🌲 Trees — DSA Notes

> **Goal:** Job prep + LeetCode practice. For revision only — assumes basic DSA knowledge.
> Last updated: April 2026

---

## 📌 Quick Reference — Core Concepts

| Concept       | Definition                                  |
| ------------- | ------------------------------------------- |
| Height        | Longest path from root to a leaf            |
| Depth         | Distance of a node from root                |
| Balanced Tree | Height difference of left/right subtree ≤ 1 |
| BST Property  | left < root < right (at every node)         |
| Inorder BST   | Always gives sorted (ascending) output      |

**Tree node structure (C++):**

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

---

## 🔁 Traversals

### Inorder (Left → Root → Right)

- **Key use:** Get sorted output from BST
- Recursive: straightforward helper function
- Iterative: use a **stack** + pointer `curr`
  - Push left chain → pop & visit → move right → repeat

**Iterative logic (mental model):**

```
curr = root
while curr != null OR stack not empty:
    go left as far as possible, pushing each node
    pop → visit → move to right child
```

### Preorder / Postorder

- Preorder (Root → L → R): useful for copying/serializing a tree
- Postorder (L → R → Root): useful for deletion, bottom-up problems

### BFS / Level Order

- Use a **queue**
- Process level by level: snapshot `queue.size()` at start of each level → loop that many times

---

## 🧩 Problems Solved

---

### 1. Binary Tree Inorder Traversal

**LC 94** | Easy | ⭐⭐⭐⭐⭐

**Recursive:** trivial helper. Base case = null node.

**Iterative (important for interviews):**

- Stack + `curr` pointer
- Push left chain → pop → visit → go right
- Time: O(n) | Space: O(h)

> 💡 **Interview tip:** If asked to avoid recursion, go straight to this iterative pattern. It's the standard.

---

### 2. Same Tree

**LC 100** | Easy | ⭐⭐⭐⭐⭐

**Problem:** Are two trees identical (same structure + same values)?

**Logic — 3 base cases, then recurse:**

1. Both null → `true`
2. One null → `false`
3. Values differ → `false`
4. Recurse on (left, left) and (right, right)

**Approaches:**

|                                | Space | Notes                  |
| ------------------------------ | ----- | ---------------------- |
| Recursive DFS                  | O(h)  | Default choice         |
| Iterative BFS (queue of pairs) | O(w)  | Good for wide trees    |
| Iterative DFS (stack of pairs) | O(h)  | Avoids recursion limit |

> 💡 **Key insight:** Push/pop _pairs_ of nodes — not individual nodes.

**Common interview follow-ups:**

- Mirrored trees? → change pairing to `(left, right)` and `(right, left)` → becomes Symmetric Tree
- Subtree check? → run `isSameTree` at every node of the main tree

---

### 3. Symmetric Tree

**LC 101** | Easy | ⭐⭐⭐⭐⭐

**Problem:** Is a tree a mirror of itself?

**Core insight:** Tree is symmetric iff left subtree = mirror of right subtree.

**Mirror check logic:**

1. Both null → `true`
2. One null → `false`
3. Values differ → `false`
4. Recurse: `(p->left, q->right)` AND `(p->right, q->left)` ← **the key flip**

**Iterative BFS:** Push pairs in mirror order into queue:

- outer pair: `(t1->left, t2->right)`
- inner pair: `(t1->right, t2->left)`

> 💡 **Same Tree vs Symmetric Tree:**
>
> - Same Tree: compare `(L, L)` and `(R, R)`
> - Symmetric: compare `(L, R)` and `(R, L)` — just swap one side

---

### 4. Maximum Depth of Binary Tree

**LC 104** | Easy | ⭐⭐⭐⭐⭐

**Problem:** Find the height of the tree.

**My approach — BFS (Level Order):**

- Use a queue, count levels
- Each full sweep of a level = +1 depth
- Process exactly `queue.size()` nodes per level

**Alternative — Recursive DFS (also great):**

```
maxDepth(node) = 1 + max(maxDepth(left), maxDepth(right))
base case: null → 0
```

> 💡 **BFS gives depth naturally** (counts levels). Recursive DFS is more concise. Both O(n) time, O(h) space (BFS is O(w) space).

---

### 5. Convert Sorted Array to BST

**LC 108** | Easy | ⭐⭐⭐⭐

**Problem:** Build a _height-balanced_ BST from a sorted array.

**Key insight:** Always pick the **middle element** as root → guarantees balance.

**Logic:**

```
buildBST(left, right):
    if left > right → return null
    mid = left + (right - left) / 2
    root = new node(nums[mid])
    root->left  = buildBST(left, mid - 1)
    root->right = buildBST(mid + 1, right)
    return root
```

- Time: O(n) — every element becomes a node once
- Space: O(log n) — balanced tree height for recursion stack

> 💡 **Why mid = left + (right-left)/2?** Avoids integer overflow (safer than (left+right)/2).

---

## 🔗 Problem Connections (Pattern Map)

```
Inorder Traversal
    └── BST Sorted Output → LC 230 Kth Smallest
    └── Validate BST → LC 98

Same Tree
    └── Symmetric Tree (flip pairing)
    └── Subtree of Another Tree (use as helper)
    └── Merge Two Binary Trees

Max Depth
    └── Min Depth → LC 111
    └── Balanced Binary Tree → LC 110
    └── Diameter of Binary Tree → LC 543

Sorted Array to BST
    └── Sorted List to BST → LC 109
    └── Balance a BST → LC 1382
```

---

## ⚡ Patterns Cheat Sheet

### Pattern 1: Recursive Tree Equality

```
base: both null → true
base: one null → false
base: values differ → false
recurse on children
```

Used in: Same Tree, Symmetric Tree, Subtree check

### Pattern 2: Level Order (BFS)

```
push root to queue
while queue not empty:
    size = queue.size()
    loop size times: pop, process, push children
    count++
```

Used in: Max Depth, Level Order Traversal, Right Side View

### Pattern 3: Divide & Conquer on Tree

```
solve(node):
    if null → base answer
    left_ans = solve(node->left)
    right_ans = solve(node->right)
    return combine(node, left_ans, right_ans)
```

Used in: Max Depth, Sorted Array to BST, Max Path Sum

### Pattern 4: Iterative DFS with Stack (pair of nodes)

```
push {nodeA, nodeB} to stack
while not empty:
    pop pair
    check conditions
    push child pairs
```

Used in: Same Tree, Symmetric Tree (iterative)

---

## 🎯 Interview Tips

- **Always clarify:** Can values be negative? Can tree be empty? Is it a BST?
- **State complexity upfront** before coding
- **Skewed tree = O(n) space** on recursion stack — mention this when asked about worst case
- **BFS vs DFS choice:**
  - Wide trees → DFS is better (less memory)
  - Deep trees → BFS is better (avoids stack overflow)
  - Level-by-level needed → BFS
- **Hashing optimization** for comparing large trees: hash each subtree (Merkle tree style), compare in O(1) — mention this for bonus points
- **The 3 null checks** (both null, one null, value differ) appear in almost every tree comparison problem — memorize this as a unit

---

## 📋 Problems Queue (Next to Solve)

| Problem                 | LC  | Difficulty | Why                 |
| ----------------------- | --- | ---------- | ------------------- |
| Min Depth               | 111 | Easy       | BFS variant         |
| Balanced Binary Tree    | 110 | Easy       | Uses max depth      |
| Diameter of Binary Tree | 543 | Easy       | Max depth variation |
| Invert Binary Tree      | 226 | Easy       | Classic             |
| Path Sum                | 112 | Easy       | DFS with tracking   |
| Kth Smallest in BST     | 230 | Medium     | Inorder traversal   |
| Validate BST            | 98  | Medium     | Inorder / bounds    |
| Subtree of Another Tree | 572 | Easy       | Same tree helper    |
| Lowest Common Ancestor  | 236 | Medium     | Important pattern   |
| Binary Tree Level Order | 102 | Medium     | BFS                 |

---

_Notes are personal — written for fast revision, not explanation to others._
