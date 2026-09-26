# Complexity Analysis: Binary Search Tree vs. Linear Search

This document provides a formal mathematical analysis of the **Time Complexity** and **Space Complexity** for all data structures and algorithms implemented in the Bookstore ISBN Management System.

---

## 1. Summary of Theoretical Complexities

Let:
- $N$ = Total number of ISBN keys ($N = 9$ in this experiment).
- $h$ = Height of the Binary Search Tree (maximum number of edges from the root to a leaf, $h = 3$; number of levels = $h + 1 = 4$).

| Operation / Algorithm | Best-Case Time | Average-Case Time | Worst-Case Time | Auxiliary Space Complexity |
| :--- | :---: | :---: | :---: | :---: |
| **BST Node Insertion (Single)** | $O(1)$ | $O(\log N)$ | $O(N)$ | $O(h)$ (recursion stack) |
| **BST Construction ($N$ nodes)** | $O(N \log N)$ | $O(N \log N)$ | $O(N^2)$ | $O(N)$ (tree nodes) + $O(h)$ |
| **BST Traversal (In/Pre/Post)** | $O(N)$ | $O(N)$ | $O(N)$ | $O(h)$ (recursion stack) |
| **BST Search** | $O(1)$ | $O(\log N)$ | $O(N)$ | $O(1)$ (iterative) or $O(h)$ (recursive) |
| **Linear Search** | $O(1)$ | $O(N)$ | $O(N)$ | $O(1)$ |

---

## 2. In-Depth Time Complexity Analysis

### A. Binary Search Tree (BST) Operations

#### 1. BST Search
- **Mechanism:** At each node, the search key is compared with the current node's ISBN.
  - If equal, search succeeds.
  - If less, move left.
  - If greater, move right.
- **Dependency on Height ($h$):** At each step down the tree, one edge is traversed. Hence, the maximum number of comparisons is strictly bounded by the height of the tree:
  $$\text{Comparisons}_{\text{max}} = h + 1$$
- **Best Case:** $O(1)$
  - Occurs when the search key resides at the root node (e.g., searching for `45`). Requires exactly 1 comparison.
- **Average Case:** $O(\log N)$
  - When keys are inserted in random or balanced order, the tree height is $h = \lfloor \log_2 N \rfloor$.
  - For $N = 9$, $\lceil \log_2(9+1) \rceil = 4$ levels.
- **Worst Case:** $O(N)$
  - Occurs when the BST degenerates into a linear chain / linked list (skewed tree), which happens if keys are inserted in strictly ascending or descending order. In that case, $h = N - 1$.
- **Observed in this Dataset:**
  - Our constructed tree is well-balanced ($h = 3$).
  - For key `25`: 4 comparisons ($= h + 1$).
  - For key `55`: 4 comparisons ($= h + 1$).
  - For key `90`: 3 comparisons ($\le h$).

#### 2. BST Construction
- Constructing the BST requires inserting $N$ keys sequentially.
- **Average Case:**
  $$\sum_{i=1}^{N} O(\log i) = O(\log(N!)) = O(N \log N)$$
- **Worst Case (Skewed):**
  $$\sum_{i=1}^{N} i = \frac{N(N+1)}{2} = O(N^2)$$

#### 3. BST Traversals (Inorder, Preorder, Postorder)
- Every node in the tree is visited exactly once, performing constant $O(1)$ work per node.
- Thus, the time complexity is strictly $\Theta(N)$.

---

### B. Linear Search Operations

- **Mechanism:** Sequentially scans the array starting from index $0$ to index $N - 1$.
- **Best Case:** $O(1)$
  - Occurs when the target element is at index 0 (e.g., searching for `45`). Requires 1 comparison.
- **Average Case:** $O(N)$
  - On average, assuming uniform probability $P = 1/N$ of being at any index:
    $$\text{Average Comparisons} = \frac{1}{N} \sum_{i=1}^{N} i = \frac{N + 1}{2}$$
  - For $N = 9$, expected comparisons $= (9 + 1)/2 = 5$.
- **Worst Case:** $O(N)$
  - Occurs when the target element is at the last position (index $N-1$) or is absent from the array (requiring checking all $N$ elements).
  - For $N = 9$, worst-case comparisons $= 9$.
- **Observed in this Dataset:**
  - Key `25` (at index 7): 8 comparisons.
  - Key `55` (at index 8): 9 comparisons.
  - Key `90` (absent): 9 comparisons.

---

## 3. Space Complexity Analysis

### A. Binary Search Tree
1. **Structural Memory:**
   - Each node contains:
     - 1 integer (`isbn`): 4 bytes
     - 2 pointers (`left`, `right`): 16 bytes (on 64-bit architecture)
     - Total per node $\approx$ 24 bytes (plus allocator overhead).
   - For $N$ nodes, heap memory allocated $= O(N)$.
2. **Auxiliary Stack Space:**
   - Traversals and recursive operations utilize the system call stack.
   - Stack frame depth is proportional to the tree height $h$:
     - Balanced Tree: $O(\log N)$
     - Degenerate Tree: $O(N)$
   - Iterative search implementation requires only $O(1)$ auxiliary space.

### B. Linear Array
1. **Structural Memory:**
   - Contiguous memory block: $N \times \text{sizeof(int)} = 9 \times 4 = 36$ bytes.
   - Total space $= O(N)$.
2. **Auxiliary Space:**
   - Linear search operates in-place using a single loop counter index: $O(1)$ auxiliary space.

---

## 4. Key Takeaways

1. **Search Efficiency Gap:** While Linear Search scales linearly with $N$ ($O(N)$), balanced BST Search scales logarithmically ($O(\log N)$).
2. **As $N$ grows large (e.g., $N = 1,000,000$ bookstore inventory):**
   - **Linear Search:** Up to $1,000,000$ comparisons.
   - **Balanced BST Search:** At most $\lceil \log_2(1,000,000) \rceil \approx 20$ comparisons.
