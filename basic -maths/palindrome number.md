# Palindrome Number (LeetCode)

## Problem

Given an integer **x**, return **true** if the integer is a **palindrome**, and **false** otherwise.

A number is a palindrome if it reads the same **forward and backward**.

---

## Example

### Example 1

**Input**

```
x = 121
```

**Output**

```
true
```

**Explanation**

121 reversed is 121, so it is a palindrome.

---

### Example 2

**Input**

```
x = -121
```

**Output**

```
false
```

**Explanation**

When reversed it becomes 121-, which is not a valid palindrome.

---

### Example 3

**Input**

```
x = 10
```

**Output**

```
false
```

**Explanation**

Reversing 10 gives 01, which is not equal to 10.

---

## Approach

1. Store the original number in a variable `dup`.
2. Reverse the digits of the number using modulo `%` and division `/`.
3. Compare the reversed number with the original number.
4. If both numbers are equal, the number is a palindrome.

---

## C++ Solution

```cpp
// Problem: Palindrome Number
// Platform: LeetCode
// Approach: Reverse number and compare with original
// Time Complexity: O(log10 n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        int ld = 0;
        int rev = 0;
        int dup = x;

        while(x > 0){
            ld = x % 10;

            if(rev > INT_MAX/10 || rev < INT_MIN/10){
                return 0;
            }

            rev = (rev * 10) + ld;
            x = x / 10;
        }

        return rev == dup;
    }
};
```

---

## Time Complexity

```
O(log10 n)
```

The number of digits in `n` determines the number of iterations.

---

## Space Complexity

```
O(1)
```

No extra space is used.

---

## Key Idea

A number is a palindrome if it remains the same after reversing its digits.
