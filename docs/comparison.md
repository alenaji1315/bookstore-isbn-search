# Performance Comparison & Justification Report

This document answers Part (c) of the assignment:
1. **Influence of BST Shape and Height on Search Performance**
2. **Observed vs. Theoretical Comparison Table**
3. **Engineering Conclusion & Justification for the Online Bookstore System**

---

## 1. Influence of Shape and Height on BST Search Performance

The performance of search operations in a Binary Search Tree is directly governed by its **topological shape** and its **height ($h$)**.

### A. Mathematical Height Bounds
For a BST containing $N$ nodes:
$$\lfloor \log_2 N \rfloor \le h \le N - 1$$

- **Best/Balanced Shape ($h = \lfloor \log_2 N \rfloor$):**
  - When keys are inserted in an order that evenly distributes elements across both left and right subtrees (e.g., our bookstore sequence starting with median-like key `45`), the tree becomes balanced.
  - The height is minimized to $O(\log_2 N)$.
  - Every comparison cuts the search space approximately in half, identical to binary search.
  - Search time is bounded by **$O(\log N)$**.

- **Worst/Degenerate Shape ($h = N - 1$):**
  - If keys are inserted in sorted order (e.g., `10, 20, 25, 30, 45, 50, 55, 60, 70`), the BST degenerates into a **skewed linked list**.
  - All nodes branch in a single direction (all right or all left).
  - Search time degenerates to **$O(N)$**, completely losing the advantages of binary tree search.

### B. Analysis of the Given Bookstore BST
In our experiment:
- **Given Insertion Sequence:** `45, 20, 60, 10, 30, 50, 70, 25, 55`
- **Resulting Shape:**
  - The root `45` divides the set into 4 smaller keys (`20, 10, 30, 25`) on the left and 4 larger keys (`60, 50, 70, 55`) on the right.
  - Subtree roots `20` and `60` further split the elements symmetrically.
  - Height $h = 3$ edges (4 levels: Level 0 to Level 3).
  - Maximum possible comparisons for any search in this tree is **4**, which is exceptionally close to the theoretical minimum $\lceil \log_2(9 + 1) \rceil = 4$.

---

## 2. Comparison Table: Observed vs. Theoretical Performance

The following table presents the observed execution metrics from the C program run alongside formal theoretical expectations:

| Search Key | Item Present? | BST Search Comparisons (Observed) | Linear Search Comparisons (Observed) | Reduction in Comparisons | Theoretical BST Search Complexity | Theoretical Linear Search Complexity |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **25** | Yes | **4** | **8** | **50.0%** | $O(h) \approx O(\log N)$ | $O(N)$ (found at index 7) |
| **55** | Yes | **4** | **9** | **55.6%** | $O(h) \approx O(\log N)$ | $O(N)$ (found at index 8) |
| **90** | No | **3** | **9** | **66.7%** | $O(h) \approx O(\log N)$ | $O(N)$ (scanned all 9 items) |

### Key Observations from the Data:
1. **Target Search for `25`:**
   - Linear search traversed 8 out of 9 elements because `25` was placed near the end of the array (index 7).
   - BST search required only 4 comparisons (`45 -> 20 -> 30 -> 25`).
2. **Target Search for `55`:**
   - Linear search traversed all 9 elements because `55` was at the very last index (index 8).
   - BST search reached `55` in only 4 comparisons (`45 -> 60 -> 50 -> 55`).
3. **Unsuccessful Search for `90`:**
   - Linear search was forced to inspect all 9 elements before concluding the item was absent.
   - BST search quickly navigated down the rightmost branch (`45 -> 60 -> 70 -> NULL`) and terminated in just 3 comparisons, demonstrating the superiority of early termination in hierarchical search.

---

## 3. Final Conclusion & Justification

### Which method is preferable for the online bookstore dataset?
**Conclusion: The Binary Search Tree (BST) approach is decisively preferable.**

### Justifications:

1. **Substantial Reduction in Search Cost:**
   - Even on a tiny dataset of only 9 keys, BST search decreased comparisons by **50% to 66.7%**.
   - For an online bookstore with tens of thousands of books ($N = 100,000$), linear search averages $50,000$ operations per lookup, whereas a balanced BST requires only $\approx 17$ operations.

2. **Early Elimination in Unsuccessful Searches:**
   - Customer searches frequently query ISBNs that are out of stock or not in the catalog (e.g., key `90`).
   - In an unsorted linear array, every missing item forces a complete scan ($N$ comparisons).
   - In a balanced BST, absence is detected in $O(\log N)$ time (3 comparisons in our test).

3. **Inherent Ordering (Inorder Traversal):**
   - An online bookstore needs to display catalogs, generate price lists, and filter by ISBN ranges.
   - Inorder traversal on a BST naturally yields all items in sorted order in $O(N)$ time without requiring a separate sorting pass.

4. **Dynamic Insertions and Deletions:**
   - New books are constantly added and discontinued books are removed.
   - Inserting or deleting in an array requires shifting elements ($O(N)$), whereas a BST handles dynamic insertions in $O(\log N)$ time.

> **Recommendation for Production:**
> While an ordinary BST is optimal for this input sequence due to balanced insertion, production systems should use self-balancing variants (such as **AVL Trees** or **Red-Black Trees**) or **B-Trees / B+ Trees** (for disk-based databases) to guarantee $O(\log N)$ performance regardless of insertion order.
