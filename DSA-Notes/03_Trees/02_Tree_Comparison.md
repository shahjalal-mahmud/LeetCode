# 🌳 Tree Comparison Problems

> **Purpose:** Problems that compare two trees or check tree properties against each other

---

## 📋 Problem 1: Same Tree

**LeetCode 100** | [🔗 View Problem](https://leetcode.com/problems/same-tree/description/)

**Difficulty:** Easy | **Frequency:** ⭐⭐⭐⭐⭐ (Very Common)

### Problem Statement

Given roots of two binary trees `p` and `q`, check if they are identical (same structure AND same values).

### Solution 1: Recursive DFS ✅ My Solution

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;  // Both empty ✅
        if(p == nullptr || q == nullptr) return false; // One empty ❌
        if(p->val != q->val) return false;             // Values differ ❌

        // Check both subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
```

**Complexity:**

- Time: `O(n)` - visit each node once
- Space: `O(h)` - recursion stack depth (h = height)
  - Best case (balanced): `O(log n)`
  - Worst case (skewed): `O(n)`

**Why this works:** Base cases first, then divide & conquer on subtrees.

---

### Solution 2: Iterative BFS (Level Order)

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});

        while(!que.empty()) {
            auto [nodeP, nodeQ] = que.front();
            que.pop();

            if(!nodeP && !nodeQ) continue;
            if(!nodeP || !nodeQ || nodeP->val != nodeQ->val)
                return false;

            que.push({nodeP->left, nodeQ->left});
            que.push({nodeP->right, nodeQ->right});
        }
        return true;
    }
};
```

**Complexity:**

- Time: `O(n)`
- Space: `O(w)` where w = max width of tree (can be up to n/2)

**Best for:** Trees that are wide but not too deep

---

### Solution 3: Iterative DFS (Stack)

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while(!st.empty()) {
            auto [nodeP, nodeQ] = st.top();
            st.pop();

            if(!nodeP && !nodeQ) continue;
            if(!nodeP || !nodeQ || nodeP->val != nodeQ->val)
                return false;

            st.push({nodeP->right, nodeQ->right});
            st.push({nodeP->left, nodeQ->left});
        }
        return true;
    }
};
```

**Complexity:** Same as recursive DFS (time O(n), space O(h))

**Best for:** Deep trees where recursion might cause stack overflow

---

## ⚖️ Trade-offs Comparison

| Approach      | Space | Risk                       | Readability | Use Case                         |
| ------------- | ----- | -------------------------- | ----------- | -------------------------------- |
| Recursive DFS | O(h)  | Stack overflow if too deep | ⭐⭐⭐⭐⭐  | Default, balanced trees          |
| Iterative BFS | O(w)  | Memory heavy if wide       | ⭐⭐⭐      | Wide trees, level-by-level check |
| Iterative DFS | O(h)  | Manual stack management    | ⭐⭐⭐⭐    | Deep trees, avoid recursion      |

---

## 🎯 Interview Questions & Answers

### Q1: What if the trees are mirrored? (Symmetric Tree)

**Answer:** Change the pairing - compare left with right instead of left with left:

```cpp
return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
```

### Q2: How to check if one tree is a subtree of another?

**Answer:** Use `isSameTree` as helper - traverse the main tree and check at each node:

```cpp
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root) return false;
    if(isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
```

### Q3: Can we optimize for very large trees (millions of nodes)?

**Answer:** Use hashing - precompute hash values for each subtree:

- Merkle tree approach: hash(node) = hash(node.val + hash(left) + hash(right))
- Compare O(1) after precomputation
- Trade-off: Extra space + computation for first tree

### Q4: Why does recursion work? What's the base case logic?

**Answer:**

- Base case 1: Both null → true (reached leaves together)
- Base case 2: One null → false (structure mismatch)
- Base case 3: Values differ → false (value mismatch)
- Recursive case: Both subtrees must match

### Q5: Time & Space complexity explanation?

**Answer:**

- **Time O(n):** Must visit every node to be sure (can't skip)
- **Space O(h):** Call stack depth equals tree height
- **Critical point:** Skewed trees (h=n) cause O(n) space

### Q6: How would you handle null pointers in different languages?

**Answer:**

- C++: Use `nullptr` explicitly
- Java/Python: Use `null`/`None`
- JavaScript: Check `=== null`
- Key insight: Explicit null checks prevent segmentation faults

---

## 🧠 Patterns & Learnings

### Pattern Recognized: **Tree Equality Pattern**

1. Check both null → true
2. Check one null → false
3. Check values → false if mismatch
4. Recurse on children


### When to use which approach

- **Interview Default:** Recursive (clean, demonstrates understanding)
- **If asked about stack overflow:** Mention BFS/stack approach
- **Production deep trees:** Iterative DFS or BFS

---

## 📝 Personal Notes

**Aha moments:**

- The `continue` in BFS when both null is crucial - allows complete tree traversal
- Space complexity depends on tree SHAPE, not just node count
- This problem is the foundation for most tree comparison problems

**Common mistakes I made:**

- Initially forgot to check both null before checking values
- Mixed up order of base cases (check null first ALWAYS)

**Interview tips:**

- Start with recursive solution (30 seconds to write)
- Mention space complexity caveat for skewed trees
- Have iterative version ready if interviewer asks for optimization
- Always discuss trade-offs before writing code

---

## 🎓 Key Takeaways

1. **Always handle null cases first** - prevents null pointer errors
2. **Recursion is elegant but has stack limits** - know when to switch
3. **Tree problems = Base cases + Recurse on children** - universal pattern
4. **Space complexity = tree height** - crucial optimization point
5. **This problem = building block** - memorizing the pattern unlocks 10+ other problems

---

_Last reviewed: [25 April 2026] | Next review: After learning Symmetric Tree & Subtree problems_
