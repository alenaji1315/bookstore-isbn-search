# Comparison Table

| Feature | BST Search | Linear Search |
|---|---|---|
| Data structure | Binary Search Tree | Array/List |
| Search principle | Compare and move left/right | Check elements sequentially |
| Average time | O(log n) for balanced BST | O(n) |
| Worst-case time | O(n) | O(n) |
| Extra search space | O(h) | O(1) |
| Requires sorted data | BST property required | No |
| Search 25 | 4 comparisons | 8 comparisons |
| Search 55 | 4 comparisons | 9 comparisons |
| Search 90 | 3 comparisons | 9 comparisons |
| Advantage for this dataset | Fewer comparisons | Simpler implementation |

## Observation

For this particular dataset, BST search required fewer comparisons than linear search for all three tested keys.

The advantage is caused by the BST's relatively small height. However, if the BST becomes highly skewed, its search complexity can degrade to O(n).
