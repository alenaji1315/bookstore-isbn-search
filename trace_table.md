# Trace Tables

## 1. BST Construction Trace

| Step | Inserted ISBN | Comparison Path | Position |
|---:|---:|---|---|
| 1 | 45 | Empty tree | Root |
| 2 | 20 | 20 < 45 | Left of 45 |
| 3 | 60 | 60 > 45 | Right of 45 |
| 4 | 10 | 10 < 45, 10 < 20 | Left of 20 |
| 5 | 30 | 30 < 45, 30 > 20 | Right of 20 |
| 6 | 50 | 50 > 45, 50 < 60 | Left of 60 |
| 7 | 70 | 70 > 45, 70 > 60 | Right of 60 |
| 8 | 25 | 25 < 45, 25 > 20, 25 < 30 | Left of 30 |
| 9 | 55 | 55 > 45, 55 < 60, 55 > 50 | Right of 50 |

## 2. Final BST

```text
              45
            /    \
          20      60
         /  \    /  \
       10   30  50   70
            /     \
           25      55
```

Height = 3 edges (4 levels).

## 3. BST Search for 25

| Comparison | Current Node | Key | Decision |
|---:|---:|---:|---|
| 1 | 45 | 25 | 25 < 45 → Left |
| 2 | 20 | 25 | 25 > 20 → Right |
| 3 | 30 | 25 | 25 < 30 → Left |
| 4 | 25 | 25 | Found |

BST comparisons = **4**

## 4. BST Search for 55

| Comparison | Current Node | Key | Decision |
|---:|---:|---:|---|
| 1 | 45 | 55 | 55 > 45 → Right |
| 2 | 60 | 55 | 55 < 60 → Left |
| 3 | 50 | 55 | 55 > 50 → Right |
| 4 | 55 | 55 | Found |

BST comparisons = **4**

## 5. BST Search for 90

| Comparison | Current Node | Key | Decision |
|---:|---:|---:|---|
| 1 | 45 | 90 | 90 > 45 → Right |
| 2 | 60 | 90 | 90 > 60 → Right |
| 3 | 70 | 90 | 90 > 70 → Right |
| — | NULL | 90 | Not Found |

BST comparisons = **3**

## 6. Linear Search for 25

Original array:

`45, 20, 60, 10, 30, 50, 70, 25, 55`

Comparisons:

`45 ✗ → 20 ✗ → 60 ✗ → 10 ✗ → 30 ✗ → 50 ✗ → 70 ✗ → 25 ✓`

Linear comparisons = **8**

## 7. Linear Search for 55

Comparisons:

`45 ✗ → 20 ✗ → 60 ✗ → 10 ✗ → 30 ✗ → 50 ✗ → 70 ✗ → 25 ✗ → 55 ✓`

Linear comparisons = **9**

## 8. Linear Search for 90

Comparisons:

`45 ✗ → 20 ✗ → 60 ✗ → 10 ✗ → 30 ✗ → 50 ✗ → 70 ✗ → 25 ✗ → 55 ✗`

Linear comparisons = **9**

## 9. Final Search Comparison

| Search Key | BST Result | BST Comparisons | Linear Result | Linear Comparisons |
|---:|---|---:|---|---:|
| 25 | Found | 4 | Found | 8 |
| 55 | Found | 4 | Found | 9 |
| 90 | Not Found | 3 | Not Found | 9 |
