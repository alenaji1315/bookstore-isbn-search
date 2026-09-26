# Online Bookstore ISBN Management: BST vs. Linear Search

A comprehensive Data Structures and Algorithms assignment implementing and comparing **Binary Search Tree (BST)** and **Linear Search** in C.

---

## 📋 Problem Statement

An online bookstore stores the following ISBN keys:
```
45, 20, 60, 10, 30, 50, 70, 25, 55
```

- **Part A:** Construct a Binary Search Tree (BST) by inserting the ISBNs in the given order. Execute the program and display the resulting tree using **Inorder**, **Preorder**, and **Postorder** traversals.
- **Part B:** Search for keys `25`, `55`, and `90` using:
  - BST Search
  - Linear Search
  - Record the number of comparisons required for each search.
- **Part C:** Analyze how the shape and height of the BST influence search performance. Compare the observed number of comparisons with the theoretical complexity of BST Search and Linear Search. Conclude which method would be preferable for the given dataset and why.

---

## 📁 Repository Structure

```
.
├── Makefile                # Build and execution automation script
├── README.md               # Primary assignment documentation and report
├── data/
│   └── input.txt           # Input ISBN keys and search queries
├── docs/
│   ├── trace_table.md      # Detailed trace tables for insertions, traversals & search
│   ├── complexity.md       # Theoretical Time & Space complexity analysis
│   └── comparison.md       # Performance comparison and engineering justification
├── output/
│   └── output.txt          # Terminal output from program execution
└── src/
    └── main.c              # Complete C source code implementation
```

---

## ⚙️ Compilation & Execution

### Prerequisites
- GCC Compiler supporting C11 (`gcc --version`)
- Make utility (`make --version`)

### Quick Start
To compile and execute the program, saving output to `output/output.txt`:
```bash
make run
```

### Manual Compilation
```bash
# Compile
gcc -Wall -Wextra -std=c11 -O2 src/main.c -o bookstore_search

# Run
./bookstore_search

# Clean
rm -f bookstore_search
```

---

## 🖥️ Execution Output

```
=========================================================================
       ONLINE BOOKSTORE ISBN MANAGEMENT SYSTEM: BST vs LINEAR SEARCH     
=========================================================================

-------------------------------------------------------------------------
PART A: BST Construction and Traversals
-------------------------------------------------------------------------
Input ISBN sequence for insertion:
  45, 20, 60, 10, 30, 50, 70, 25, 55

BST successfully constructed.

Traversals of the Constructed BST:
  1. Inorder Traversal   (L, Root, R): 10 20 25 30 45 50 55 60 70 
     (Note: Inorder yields strictly sorted ISBNs in ascending order)

  2. Preorder Traversal  (Root, L, R): 45 20 10 30 25 60 50 55 70 

  3. Postorder Traversal (L, R, Root): 10 25 30 20 55 50 70 60 45 

Tree Properties:
  - Total Nodes: 9
  - Tree Height (edges from root): 3
  - Maximum Levels: 4

Visual Tree Representation (Rotated 90 degrees counter-clockwise):
-----------------------------------------------------------------

          [70]

     [60]

               [55]

          [50]

[45]

          [30]

               [25]

     [20]

          [10]
-----------------------------------------------------------------

-------------------------------------------------------------------------
PART B: Searching Keys [25, 55, 90]
-------------------------------------------------------------------------
Searching for ISBN Key: 25
  [BST Search]:
    Path Traversed: 45 -> 20 -> 30 -> 25
    Result: FOUND | Comparisons: 4
  [Linear Search]:
    Array Inspection: Checked indices 0 to 7
    Result: FOUND | Comparisons: 8

Searching for ISBN Key: 55
  [BST Search]:
    Path Traversed: 45 -> 60 -> 50 -> 55
    Result: FOUND | Comparisons: 4
  [Linear Search]:
    Array Inspection: Checked indices 0 to 8
    Result: FOUND | Comparisons: 9

Searching for ISBN Key: 90
  [BST Search]:
    Path Traversed: 45 -> 60 -> 70
    Result: NOT FOUND | Comparisons: 3
  [Linear Search]:
    Array Inspection: Checked indices 0 to 8
    Result: NOT FOUND | Comparisons: 9

-------------------------------------------------------------------------
COMPARISON SUMMARY TABLE
-------------------------------------------------------------------------
+------------+----------------+-------------------+----------------------+
| Search Key | Search Status  | BST Comparisons   | Linear Comparisons   |
+------------+----------------+-------------------+----------------------+
| 25         | FOUND          | 4                 | 8                    |
| 55         | FOUND          | 4                 | 9                    |
| 90         | NOT FOUND      | 3                 | 9                    |
+------------+----------------+-------------------+----------------------+
```

---

## 🌳 Binary Search Tree Architecture

```
                  [45]  (Level 0 / Root)
                /      \
            [20]        [60]  (Level 1)
           /    \      /    \
        [10]    [30] [50]   [70]  (Level 2)
                /      \
             [25]      [55]  (Level 3)
```

- **Height ($h$):** 3 edges
- **Levels:** 4
- **Root Element:** 45

---

## 📊 Comparison Table: Observed vs. Theoretical

| Search Key | Status | BST Comparisons (Observed) | Linear Comparisons (Observed) | Comparison Reduction | Theoretical BST Complexity | Theoretical Linear Complexity |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **25** | FOUND | **4** | **8** | **50.0%** | $O(h) \approx O(\log N)$ | $O(N)$ (index 7) |
| **55** | FOUND | **4** | **9** | **55.6%** | $O(h) \approx O(\log N)$ | $O(N)$ (index 8) |
| **90** | NOT FOUND | **3** | **9** | **66.7%** | $O(h) \approx O(\log N)$ | $O(N)$ (scanned all) |

---

## 📈 Complexity Analysis Summary

| Algorithm / Operation | Best Case Time | Average Case Time | Worst Case Time | Auxiliary Space Complexity |
| :--- | :---: | :---: | :---: | :---: |
| **BST Search** | $O(1)$ | $O(\log N)$ | $O(N)$ (Skewed tree) | $O(1)$ (iterative) / $O(h)$ (recursive) |
| **Linear Search** | $O(1)$ | $O(N)$ | $O(N)$ | $O(1)$ |
| **BST Insertion** | $O(1)$ | $O(\log N)$ | $O(N)$ | $O(h)$ |
| **BST Traversals** | $O(N)$ | $O(N)$ | $O(N)$ | $O(h)$ |

For formal proofs and detailed derivations, refer to [docs/complexity.md](docs/complexity.md).

---

## 🔍 Influence of Tree Shape and Height on Performance

1. **Height as the Performance Upper Bound:**
   - In a BST, the maximum comparisons required to locate or reject any key is $h + 1$.
   - For balanced trees, $h = \lfloor \log_2 N \rfloor \implies O(\log N)$.
   - For degenerate/skewed trees (when data is entered pre-sorted), $h = N - 1 \implies O(N)$, eroding all benefits over linear search.
2. **Behavior on this Dataset:**
   - Because the root `45` acts as a near-median divider, the resulting tree is nearly complete and balanced ($h = 3$).
   - No search ever exceeds 4 comparisons, whereas linear search requires up to 9 comparisons.

---

## 💡 Final Conclusion & Engineering Justification

**Recommendation:** **Binary Search Tree (BST) is the preferable data structure.**

### Rationale:
1. **Search Speed:** Reduces comparison operations by **50% to 66.7%** even on this small dataset of 9 items. For real-world catalogs ($N = 100,000$), BST requires $\approx 17$ comparisons vs. $50,000$ on average for linear search.
2. **Rapid Rejection of Missing Items:** Missing queries (such as ISBN `90`) are rejected in just 3 comparisons instead of having to inspect every catalog entry.
3. **Sorted Catalog Retrieval:** Inorder traversal produces ascending ISBN ordering in $O(N)$ time without sorting overhead.
4. **Dynamic Maintenance:** Enables insertion and deletion of book titles in $O(\log N)$ time, avoiding array shift operations ($O(N)$).

---

## 🚀 How to Upload to GitHub

To submit this project to GitHub:

1. **Initialize Git repository:**
   ```bash
   cd bookstore-isbn-search
   git init
   git add .
   git commit -m "Complete Bookstore ISBN BST vs Linear Search assignment"
   ```

2. **Link to your GitHub remote and push:**
   ```bash
   # Create a repository on GitHub (e.g. bookstore-isbn-search), then:
   git branch -M main
   git remote add origin https://github.com/<your-username>/bookstore-isbn-search.git
   git push -u origin main
   ```

3. **Submit:** Copy the GitHub repository URL and submit it as requested.
