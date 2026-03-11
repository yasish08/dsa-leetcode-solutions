# Reverse Integer (LeetCode)

## Problem

Given a signed 32-bit integer **x**, return **x with its digits reversed**.

If reversing **x** causes the value to go outside the signed 32-bit integer range
`[-2^31 , 2^31 − 1]`, return **0**.

---

## Approach

We reverse the number digit by digit using **modulo and division**.

### Steps

1. Extract the last digit using `x % 10`.
2. Multiply the current reversed number by `10`.
3. Add the extracted digit.
4. Reduce the original number using `x / 10`.
5. Before updating the reversed number, check for **overflow**.

If the reversed value exceeds the **32-bit integer limit**, return `0`.

---

## C++ Implementation

```cpp
class Solution {
public:
    int reverse(int x) {
        long long reverse=0;
        long long ld=0;
        while(x!=0){
            ld=x%10;
            if(reverse > INT_MAX/10 || reverse < INT_MIN/10)
                return 0;
            reverse=(reverse*10)+ld;
            x=x/10;
        } 
        return reverse; 
    }
};
```

---

## Time Complexity

**O(log10 n)**
We process each digit once.

## Space Complexity

**O(1)**
Only constant extra space is used.

---

## Key Concept

The **overflow check** ensures the reversed number stays within the 32-bit integer range.
