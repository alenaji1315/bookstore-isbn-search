# Trace Tables: Bookstore ISBN Search

This document records the step-by-step intermediate states and trace tables for:
1. **Binary Search Tree (BST) Construction**
2. **Tree Traversals (Inorder, Preorder, Postorder)**
3. **Search Operations (BST Search vs. Linear Search for Keys 25, 55, and 90)**

---

## 1. BST Construction Trace Table

- **Given ISBN Insertion Order:** `[45, 20, 60, 10, 30, 50, 70, 25, 55]`
- **Total Keys ($N$):** 9

| Step | Key Inserted | Traversal / Comparison Sequence | Decision & Pointer Updates | Subtree / Insertion Position |
| :---: | :---: | :--- | :--- | :--- |
| **1** | **45** | Tree is currently empty (`root == NULL`). | Create root node with value 45. | `root = Node(45)` |
| **2** | **20** | Compare with root (45): `20 < 45`. | Move to `root->left`. As `root->left == NULL`, attach here. | Left child of 45 |
| **3** | **60** | Compare with root (45): `60 > 45`. | Move to `root->right`. As `root->right == NULL`, attach here. | Right child of 45 |
| **4** | **10** | 1. Compare with 45: `10 < 45` &rarr; Go Left.<br>2. Compare with 20: `10 < 20` &rarr; Go Left. | As `20->left == NULL`, attach here. | Left child of 20 |
| **5** | **30** | 1. Compare with 45: `30 < 45` &rarr; Go Left.<br>2. Compare with 20: `30 > 20` &rarr; Go Right. | As `20->right == NULL`, attach here. | Right child of 20 |
| **6** | **50** | 1. Compare with 45: `50 > 45` &rarr; Go Right.<br>2. Compare with 60: `50 < 60` &rarr; Go Left. | As `60->left == NULL`, attach here. | Left child of 60 |
| **7** | **70** | 1. Compare with 45: `70 > 45` &rarr; Go Right.<br>2. Compare with 60: `70 > 60` &rarr; Go Right. | As `60->right == NULL`, attach here. | Right child of 60 |
| **8** | **25** | 1. Compare with 45: `25 < 45` &rarr; Go Left.<br>2. Compare with 20: `25 > 20` &rarr; Go Right.<br>3. Compare with 30: `25 < 30` &rarr; Go Left. | As `30->left == NULL`, attach here. | Left child of 30 |
| **9** | **55** | 1. Compare with 45: `55 > 45` &rarr; Go Right.<br>2. Compare with 60: `55 < 60` &rarr; Go Left.<br>3. Compare with 50: `55 > 50` &rarr; Go Right. | As `50->right == NULL`, attach here. | Right child of 50 |

---

## 2. Resulting Binary Search Tree Architecture

```
                  [45]  (Level 0 / Root)
                /      \
            [20]        [60]  (Level 1)
           /    \      /    \
        [10]    [30] [50]   [70]  (Level 2)
                /      \
             [25]      [55]  (Level 3 / Leaves)
```

- **Total Nodes ($N$):** 9
- **Height of Tree (edges):** $h = 3$
- **Total Levels:** 4 (Levels 0, 1, 2, 3)
- **Balance Characteristic:** Well-balanced (every sub-tree depth difference $\le 1$).

---

## 3. Tree Traversals Trace

### A. Inorder Traversal (Left &rarr; Root &rarr; Right)
*Traverses the tree to produce non-decreasing sorted order.*

| Step | Current Action | Visited Node / Output | Output Sequence Accumulated |
| :---: | :--- | :---: | :--- |
| 1 | Recurse leftmost from 45 &rarr; 20 &rarr; 10 | **10** | `10` |
| 2 | Backtrack to 20, visit root | **20** | `10, 20` |
| 3 | Move to right of 20 (30), go left to 25 | **25** | `10, 20, 25` |
| 4 | Backtrack to 30, visit root | **30** | `10, 20, 25, 30` |
| 5 | Backtrack to root of tree | **45** | `10, 20, 25, 30, 45` |
| 6 | Move right to 60, go left to 50, visit 50 | **50** | `10, 20, 25, 30, 45, 50` |
| 7 | Move right of 50 to 55, visit 55 | **55** | `10, 20, 25, 30, 45, 50, 55` |
| 8 | Backtrack to 60, visit root | **60** | `10, 20, 25, 30, 45, 50, 55, 60` |
| 9 | Move right of 60 to 70, visit 70 | **70** | `10, 20, 25, 30, 45, 50, 55, 60, 70` |

- **Final Inorder Sequence:** `10, 20, 25, 30, 45, 50, 55, 60, 70`

---

### B. Preorder Traversal (Root &rarr; Left &rarr; Right)

| Step | Action | Node Visited | Accumulated Output |
| :---: | :--- | :---: | :--- |
| 1 | Visit Root (45) | **45** | `45` |
| 2 | Visit Left Child (20) | **20** | `45, 20` |
| 3 | Visit Left Child (10) | **10** | `45, 20, 10` |
| 4 | Visit Right Child of 20 (30) | **30** | `45, 20, 10, 30` |
| 5 | Visit Left Child of 30 (25) | **25** | `45, 20, 10, 30, 25` |
| 6 | Visit Right Child of 45 (60) | **60** | `45, 20, 10, 30, 25, 60` |
| 7 | Visit Left Child of 60 (50) | **50** | `45, 20, 10, 30, 25, 60, 50` |
| 8 | Visit Right Child of 50 (55) | **55** | `45, 20, 10, 30, 25, 60, 50, 55` |
| 9 | Visit Right Child of 60 (70) | **70** | `45, 20, 10, 30, 25, 60, 50, 55, 70` |

- **Final Preorder Sequence:** `45, 20, 10, 30, 25, 60, 50, 55, 70`

---

### C. Postorder Traversal (Left &rarr; Right &rarr; Root)

| Step | Action | Node Visited | Accumulated Output |
| :---: | :--- | :---: | :--- |
| 1 | Leftmost leaf node under 20 | **10** | `10` |
| 2 | Left child of 30 | **25** | `10, 25` |
| 3 | Root of 25 (30) | **30** | `10, 25, 30` |
| 4 | Parent of 10 and 30 | **20** | `10, 25, 30, 20` |
| 5 | Leaf node under 50 | **55** | `10, 25, 30, 20, 55` |
| 6 | Parent of 55 | **50** | `10, 25, 30, 20, 55, 50` |
| 7 | Right child of 60 | **70** | `10, 25, 30, 20, 55, 50, 70` |
| 8 | Parent of 50 and 70 | **60** | `10, 25, 30, 20, 55, 50, 70, 60` |
| 9 | Overall Root of Tree | **45** | `10, 25, 30, 20, 55, 50, 70, 60, 45` |

- **Final Postorder Sequence:** `10, 25, 30, 20, 55, 50, 70, 60, 45`

---

## 4. Search Trace Tables: BST Search vs. Linear Search

Input Array for Linear Search: `[45, 20, 60, 10, 30, 50, 70, 25, 55]`

### Case 1: Search for Key `25`

#### BST Search Trace:
| Comparison # | Current Node | Comparison Expression | Outcome / Next Step |
| :---: | :---: | :--- | :--- |
| 1 | `45` | `25 < 45` | True &rarr; Move to left child (`20`) |
| 2 | `20` | `25 > 20` | True &rarr; Move to right child (`30`) |
| 3 | `30` | `25 < 30` | True &rarr; Move to left child (`25`) |
| 4 | `25` | `25 == 25` | **Match Found!** Terminate search. |
- **BST Total Comparisons:** **4**
- **Path:** `45 -> 20 -> 30 -> 25`

#### Linear Search Trace:
| Comparison # | Array Index | Element Checked | Comparison (`arr[i] == 25`) | Result |
| :---: | :---: | :---: | :---: | :--- |
| 1 | 0 | 45 | `45 == 25` | False |
| 2 | 1 | 20 | `20 == 25` | False |
| 3 | 2 | 60 | `60 == 25` | False |
| 4 | 3 | 10 | `10 == 25` | False |
| 5 | 4 | 30 | `30 == 25` | False |
| 6 | 5 | 50 | `50 == 25` | False |
| 7 | 6 | 70 | `70 == 25` | False |
| 8 | 7 | 25 | `25 == 25` | **Match Found!** Terminate search. |
- **Linear Search Total Comparisons:** **8**

---

### Case 2: Search for Key `55`

#### BST Search Trace:
| Comparison # | Current Node | Comparison Expression | Outcome / Next Step |
| :---: | :---: | :--- | :--- |
| 1 | `45` | `55 > 45` | True &rarr; Move to right child (`60`) |
| 2 | `60` | `55 < 60` | True &rarr; Move to left child (`50`) |
| 3 | `50` | `55 > 50` | True &rarr; Move to right child (`55`) |
| 4 | `55` | `55 == 55` | **Match Found!** Terminate search. |
- **BST Total Comparisons:** **4**
- **Path:** `45 -> 60 -> 50 -> 55`

#### Linear Search Trace:
| Comparison # | Array Index | Element Checked | Comparison (`arr[i] == 55`) | Result |
| :---: | :---: | :---: | :---: | :--- |
| 1 | 0 | 45 | `45 == 55` | False |
| 2 | 1 | 20 | `20 == 55` | False |
| 3 | 2 | 60 | `60 == 55` | False |
| 4 | 3 | 10 | `10 == 55` | False |
| 5 | 4 | 30 | `30 == 55` | False |
| 6 | 5 | 50 | `50 == 55` | False |
| 7 | 6 | 70 | `70 == 55` | False |
| 8 | 7 | 25 | `25 == 55` | False |
| 9 | 8 | 55 | `55 == 55` | **Match Found!** Terminate search. |
- **Linear Search Total Comparisons:** **9**

---

### Case 3: Search for Key `90` (Element Not Present)

#### BST Search Trace:
| Comparison # | Current Node | Comparison Expression | Outcome / Next Step |
| :---: | :---: | :--- | :--- |
| 1 | `45` | `90 > 45` | True &rarr; Move to right child (`60`) |
| 2 | `60` | `90 > 60` | True &rarr; Move to right child (`70`) |
| 3 | `70` | `90 > 70` | True &rarr; Move to right child (`NULL`) |
| - | `NULL` | - | Reached `NULL` pointer. Key does not exist. |
- **BST Total Comparisons:** **3**
- **Path:** `45 -> 60 -> 70 -> NULL`

#### Linear Search Trace:
| Comparison # | Array Index | Element Checked | Comparison (`arr[i] == 90`) | Result |
| :---: | :---: | :---: | :---: | :--- |
| 1 | 0 | 45 | `45 == 90` | False |
| 2 | 1 | 20 | `20 == 90` | False |
| 3 | 2 | 60 | `60 == 90` | False |
| 4 | 3 | 10 | `10 == 90` | False |
| 5 | 4 | 30 | `30 == 90` | False |
| 6 | 5 | 50 | `50 == 90` | False |
| 7 | 6 | 70 | `70 == 90` | False |
| 8 | 7 | 25 | `25 == 90` | False |
| 9 | 8 | 55 | `55 == 90` | False |
- **Linear Search Total Comparisons:** **9** (Exhausted all elements)
