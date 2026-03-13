# Rotate Array

## Problem

Given an integer array `nums`, rotate the array to the **right by `k` steps**, where `k` is non-negative.

The rotation should be done **in-place**.

---

## Examples

### Example 1

```text
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
```

Explanation
Rotate the array 3 times to the right.

Step 1 → `[7,1,2,3,4,5,6]`
Step 2 → `[6,7,1,2,3,4,5]`
Step 3 → `[5,6,7,1,2,3,4]`

---

### Example 2

```text
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
```

---

## Approach (Reverse Technique)

Instead of rotating the array step-by-step, we use the **reverse algorithm**.

### Steps

1. Compute effective rotations

   ```
   k = k % n
   ```

2. Reverse the **entire array**

3. Reverse the **first k elements**

4. Reverse the **remaining elements**

---

### Example

Array:

```
[1,2,3,4,5,6,7], k = 3
```

Step 1 → Reverse entire array

```
[7,6,5,4,3,2,1]
```

Step 2 → Reverse first k elements

```
[5,6,7,4,3,2,1]
```

Step 3 → Reverse remaining elements

```
[5,6,7,1,2,3,4]
```

Final rotated array obtained.

---

## Time Complexity

```
O(n)
```

We reverse the array three times.

---

## Space Complexity

```
O(1)
```

The rotation is done **in-place** without extra memory.

---

## C++ Implementation

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```

---

## Concepts Used

* Arrays
* In-place algorithm
* Reverse technique
* Modulo operation

---

## Author

**Yasish**
