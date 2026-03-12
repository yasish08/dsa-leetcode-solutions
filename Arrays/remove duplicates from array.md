# Remove Duplicates from Sorted Array

## Problem

Given a **sorted integer array `nums`**, remove the duplicates **in-place** such that each unique element appears only once.

The **relative order** of the elements should be kept the same.

Return the number of **unique elements `k`** in the array.

After removing duplicates, the first `k` elements of `nums` should contain the unique elements.

---

## Examples

### Example 1

```
Input: nums = [1,1,2]
Output: 2
Updated Array: [1,2,_]
```

### Example 2

```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5
Updated Array: [0,1,2,3,4,_,_,_,_,_]
```

---

## Approach (Two Pointer Technique)

Since the array is **already sorted**, duplicates will always appear **next to each other**.

We use two pointers:

* **i → Slow pointer**
  Keeps track of the position of the last unique element.

* **j → Fast pointer**
  Traverses through the array to find new unique elements.

### Steps

1. Start `i = 0` (first element is always unique).
2. Traverse the array using `j` from `1` to `n-1`.
3. If `nums[j] != nums[i]`

   * Move `i` forward.
   * Place the new unique element at `nums[i]`.
4. Finally return `i + 1` (number of unique elements).

---

## Algorithm

1. If array size is `0`, return `0`.
2. Initialize `i = 0`.
3. Traverse the array using `j`.
4. When a new element is found, move `i` and update the array.
5. Return `i + 1`.

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

No extra space is used since modification happens **in-place**.

---

## C++ Implementation

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        
        int i = 0;   // slow pointer
        
        for(int j = 1; j < n; j++) {
            
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
    }
};
```

---

## Key Concepts

* Arrays
* Two Pointer Technique
* In-place modification
* Sorted array optimization

---

## Author

**Yasish**
