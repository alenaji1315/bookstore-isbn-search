# Online Bookstore ISBN Search Using Binary Search Tree

## Data Structures and Algorithms Assignment

### Problem

An online bookstore stores the following ISBN keys:

`45, 20, 60, 10, 30, 50, 70, 25, 55`

The task is to construct a Binary Search Tree (BST), perform tree traversals, compare BST search with linear search, analyse the effect of the tree's shape and height, and determine the time and space complexity.

---

# 1. Objectives

This assignment demonstrates:

1. Construction of a Binary Search Tree using a given insertion order.
2. Inorder, preorder and postorder traversal.
3. Searching for values using BST Search.
4. Searching for the same values using Linear Search.
5. Recording the number of comparisons for each search.
6. Studying how BST height and shape affect performance.
7. Comparing observed performance with theoretical complexity.
8. Drawing a conclusion based on the execution results.

---

# 2. Input Data

The ISBNs are inserted in exactly this order:

```text
45, 20, 60, 10, 30, 50, 70, 25, 55
```

The search keys are:

```text
25, 55, 90
```

The C program used for this assignment is available in:

`bst_isbn.c`

The original input is recorded in:

`input.txt`

---

# 3. Binary Search Tree Construction

A Binary Search Tree follows this rule:

- Values smaller than a node are placed in its left subtree.
- Values greater than a node are placed in its right subtree.

Insertion sequence:

### Insert 45

The tree is empty, so 45 becomes the root.

```text
45
```

### Insert 20

20 < 45, so 20 is placed to the left.

```text
   45
  /
20
```

### Insert 60

60 > 45, so 60 is placed to the right.

```text
   45
  /  \
20    60
```

### Insert 10

10 < 45 and 10 < 20, so it becomes the left child of 20.

### Insert 30

30 < 45 but 30 > 20, so it becomes the right child of 20.

### Insert 50

50 > 45 but 50 < 60, so it becomes the left child of 60.

### Insert 70

70 > 45 and 70 > 60, so it becomes the right child of 60.

### Insert 25

25 < 45, 25 > 20 and 25 < 30, so it becomes the left child of 30.

### Insert 55

55 > 45, 55 < 60 and 55 > 50, so it becomes the right child of 50.

---

# 4. Final BST

```text
              45
            /    \
          20      60
         /  \    /  \
       10   30  50   70
            /     \
           25      55
```

The height of the tree is:

- Height in edges = **3**
- Number of levels = **4**

The longest paths from root to leaves are:

```text
45 → 20 → 30 → 25
45 → 60 → 50 → 55
```

---

# 5. Tree Traversals

## Inorder Traversal

Inorder follows:

`Left → Root → Right`

Result:

```text
10 20 25 30 45 50 55 60 70
```

An important property of a BST is that its inorder traversal produces the keys in sorted ascending order.

---

## Preorder Traversal

Preorder follows:

`Root → Left → Right`

Result:

```text
45 20 10 30 25 60 50 55 70
```

---

## Postorder Traversal

Postorder follows:

`Left → Right → Root`

Result:

```text
10 25 30 20 55 50 70 60 45
```

The complete execution output is available in:

`output.txt`

---

# 6. BST Search

The program searches for:

```text
25
55
90
```

## Search for 25

Path:

```text
45 → 20 → 30 → 25
```

Comparisons:

1. Compare 25 with 45 (`25 < 45` → Go Left).
2. Compare 25 with 20 (`25 > 20` → Go Right).
3. Compare 25 with 30 (`25 < 30` → Go Left).
4. Compare 25 with 25 (`25 == 25` → Found).

Result:

**Found in 4 comparisons.**

---

## Search for 55

Path:

```text
45 → 60 → 50 → 55
```

Comparisons:

1. Compare 55 with 45 (`55 > 45` → Go Right).
2. Compare 55 with 60 (`55 < 60` → Go Left).
3. Compare 55 with 50 (`55 > 50` → Go Right).
4. Compare 55 with 55 (`55 == 55` → Found).

Result:

**Found in 4 comparisons.**

---

## Search for 90

Path:

```text
45 → 60 → 70 → NULL
```

Comparisons:

1. Compare 90 with 45 (`90 > 45` → Go Right).
2. Compare 90 with 60 (`90 > 60` → Go Right).
3. Compare 90 with 70 (`90 > 70` → Go Right).

After 70, the right child is NULL.

Result:

**Not Found in 3 comparisons.**

Detailed traces are available in:

`trace_table.md`

---

# 7. Linear Search

The original array is:

```text
45 20 60 10 30 50 70 25 55
```

Linear search examines elements from left to right.

## Search for 25

```text
45 ✗
20 ✗
60 ✗
10 ✗
30 ✗
50 ✗
70 ✗
25 ✓
```

Comparisons = **8**

## Search for 55

```text
45 ✗
20 ✗
60 ✗
10 ✗
30 ✗
50 ✗
70 ✗
25 ✗
55 ✓
```

Comparisons = **9**

## Search for 90

Every element is checked:

```text
45 ✗
20 ✗
60 ✗
10 ✗
30 ✗
50 ✗
70 ✗
25 ✗
55 ✗
```

Comparisons = **9**

---

# 8. Search Comparison

| Search Key | BST Result | BST Comparisons | Linear Result | Linear Comparisons |
|---:|---|---:|---|---:|
| 25 | Found | 4 | Found | 8 |
| 55 | Found | 4 | Found | 9 |
| 90 | Not Found | 3 | Not Found | 9 |

The BST requires fewer comparisons for all three test cases.

---

# 9. Complexity Analysis

## BST Search

For a reasonably balanced BST:

**Average case:**

`O(log n)`

**Worst case:**

`O(n)`

The worst case occurs when the tree becomes skewed.

The auxiliary space associated with tree traversal/search is related to the height:

`O(h)`

where `h` is the tree height.

---

## Linear Search

**Best case:**

`O(1)`

**Average case:**

`O(n)`

**Worst case:**

`O(n)`

Extra space:

`O(1)`

---

## BST Insertion

Average case for a reasonably balanced tree:

`O(log n)`

Worst case:

`O(n)`

---

## Tree Traversals

Inorder, preorder and postorder visit every node once.

Time complexity:

`O(n)`

Recursive auxiliary space:

`O(h)`

---

# 10. Effect of BST Shape and Height

The performance of an ordinary BST depends heavily on its shape.

The constructed tree is reasonably balanced:

```text
              45
            /    \
          20      60
         /  \    /  \
       10   30  50   70
            /     \
           25      55
```

Its height is only 3 edges (4 levels).

This means a search can reach a required value using a small number of comparisons.

For example:

```text
BST Search for 55:

45 → 60 → 50 → 55
```

Only four comparisons are required.

---

# 11. What Happens if the BST Becomes Skewed?

Consider inserting already sorted values:

```text
10, 20, 30, 40, 50
```

The resulting tree can look like:

```text
10
  \
   20
     \
      30
        \
         40
           \
            50
```

This tree has a large height.

In such a case, BST search can degrade to:

`O(n)`

Therefore, an ordinary BST does not guarantee logarithmic search time unless its height is kept small.

---

# 12. Observed vs Theoretical Performance

For this assignment:

```text
Number of nodes = 9
BST height = 3 edges
```

Observed comparisons:

| Key | BST | Linear |
|---:|---:|---:|
| 25 | 4 | 8 |
| 55 | 4 | 9 |
| 90 | 3 | 9 |

The observations agree with the expected behaviour:

- BST search uses the tree structure to eliminate unnecessary nodes.
- Linear search examines elements sequentially.
- The relatively small BST height results in short search paths.
- Linear search requires more comparisons for the tested values.

---

# 13. Comparison Table

| Feature | BST Search | Linear Search |
|---|---|---|
| Basic method | Tree-based search | Sequential search |
| Average time | O(log n), if reasonably balanced | O(n) |
| Worst-case time | O(n) | O(n) |
| Extra search space | O(h) | O(1) |
| Data organization | BST property | No special organization |
| Search 25 | 4 comparisons | 8 comparisons |
| Search 55 | 4 comparisons | 9 comparisons |
| Search 90 | 3 comparisons | 9 comparisons |

A detailed version is available in:

`comparison_table.md`

---

# 14. Advantages of BST for This Dataset

The BST provides:

1. Fewer comparisons for all three tested searches.
2. A structured way of storing ISBN keys.
3. Efficient searching when the tree height remains small.
4. Inorder traversal that automatically produces sorted ISBNs.
5. A structure that can support dynamic insertion of new ISBNs.

---

# 15. Limitations

An ordinary BST can become inefficient if its shape becomes highly unbalanced.

For example, a skewed BST can have:

`O(n)`

search time.

For applications with very large datasets where guaranteed logarithmic performance is important, self-balancing trees such as AVL trees or Red-Black trees can be considered.

---

# 16. Final Conclusion

The ISBN keys were successfully stored in a Binary Search Tree using the given insertion order.

The resulting traversals are:

### Inorder

```text
10 20 25 30 45 50 55 60 70
```

### Preorder

```text
45 20 10 30 25 60 50 55 70
```

### Postorder

```text
10 25 30 20 55 50 70 60 45
```

The search comparison results are:

| Key | BST | Linear |
|---:|---:|---:|
| 25 | 4 | 8 |
| 55 | 4 | 9 |
| 90 | 3 | 9 |

For the given dataset, BST search required fewer comparisons for every tested key. This is because the BST has a relatively small height and allows the search space to be reduced at every comparison.

The theoretical complexity of BST search is **O(log n)** for a reasonably balanced tree and **O(n)** in the worst case. Linear search has **O(n)** average and worst-case time complexity.

Therefore, for this particular dataset, the constructed BST provides better observed search performance than linear search. The advantage depends on maintaining a suitable tree shape and does not apply to every possible BST arrangement.

---

# 17. Files in This Repository

```text
bookstore-isbn-search/
│
├── README.md
├── bst_isbn.c
├── input.txt
├── output.txt
├── trace_table.md
├── complexity_analysis.md
└── comparison_table.md
```

## File Description

| File | Purpose |
|---|---|
| `README.md` | Complete assignment documentation |
| `bst_isbn.c` | C source code |
| `input.txt` | Given ISBNs and search keys |
| `output.txt` | Program execution output |
| `trace_table.md` | BST construction and search traces |
| `complexity_analysis.md` | Time and space complexity |
| `comparison_table.md` | BST vs Linear Search comparison |

---

# 18. How to Compile and Run

Using GCC:

```bash
gcc bst_isbn.c -o bst_isbn
```

Run:

```bash
./bst_isbn
```

On Windows:

```bash
gcc bst_isbn.c -o bst_isbn.exe
bst_isbn.exe
```

---

# 19. GitHub Submission

Repository URL:

`https://github.com/alenaji1315/bookstore-isbn-search`

The repository contains:

- Source code (`bst_isbn.c`)
- Input data (`input.txt`)
- Program output (`output.txt`)
- Trace table (`trace_table.md`)
- Complexity analysis (`complexity_analysis.md`)
- Comparison table (`comparison_table.md`)
- Detailed README (`README.md`)
- Final conclusion
