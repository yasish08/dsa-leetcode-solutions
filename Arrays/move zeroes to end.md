# Move Zeroes

## Problem

Given an integer array `nums`, move all `0`s to the **end of the array** while maintaining the **relative order of the non-zero elements**.

The operation must be done **in-place** without making a copy of the array.

---

## Examples

### Example 1

```text
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

### Example 2

```text
Input: nums = [0]
Output: [0]
```

---

## Approach (Two Pointer Technique)

We use a **two-pointer approach** to move all non-zero elements to the front while pushing zeros to the end.

### Pointers Used

* **j → Position to place the next non-zero element**
* **i → Traverses the array**

### Steps

1. Initialize `j = 0`.
2. Traverse the array using `i`.
3. If `nums[i]` is **not zero**:

   * Swap `nums[i]` with `nums[j]`.
   * Increment `j`.
4. Continue until the end of the array.

This ensures:

* All **non-zero elements move to the front**
* All **zeros automatically shift to the end**

---

## Example Walkthrough

Array:

```text
[0,1,0,3,12]
```

Step 1 → Swap `1` with index `0`

```
[1,0,0,3,12]
```

Step 2 → Swap `3` with index `1`

```
[1,3,0,0,12]
```

Step 3 → Swap `12` with index `2`

```
[1,3,12,0,0]
```

Final Result:

```
[1,3,12,0,0]
```

---

## Time Complexity

```
O(n)
```

We traverse the array only once.

---

## Space Complexity

```
O(1)
```

The operation is performed **in-place**.

---

## C++ Implementation

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
```

---

## Concepts Used

* Arrays
* Two Pointer Technique
* In-place swapping
* Efficient traversal

---

## Author
yasish

**Yasish**
