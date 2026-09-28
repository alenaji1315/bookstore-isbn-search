# Complexity Analysis

## Binary Search Tree Search

For a reasonably balanced BST:

- Average time complexity: **O(log n)**
- Worst-case time complexity: **O(n)**
- Space complexity: **O(h)** for recursive tree operations / tree height, where `h` is the height.

For this dataset:

- Number of nodes, n = 9
- Height = 3 edges
- Levels = 4

The tree is reasonably balanced, so the observed search paths are short.

## Linear Search

- Best case: **O(1)**
- Average case: **O(n)**
- Worst case: **O(n)**
- Extra space: **O(1)**

Linear search checks the array from the beginning until the key is found or the array ends.

## BST Insertion

- Average case for a balanced BST: **O(log n)**
- Worst case: **O(n)**

## Traversals

Inorder, preorder and postorder each visit every node exactly once.

- Time complexity: **O(n)**
- Recursive auxiliary space: **O(h)**

## Shape and Height

The height of a BST strongly influences search performance.

A balanced BST has height approximately:

`h = O(log n)`

A skewed BST can have:

`h = O(n)`

Therefore, an ordinary BST does not always guarantee O(log n) search. Its performance depends on its shape.

## Dataset-Specific Observation

For the three tested keys:

| Key | BST Comparisons | Linear Comparisons |
|---:|---:|---:|
| 25 | 4 | 8 |
| 55 | 4 | 9 |
| 90 | 3 | 9 |

The BST uses fewer comparisons for every tested search.
