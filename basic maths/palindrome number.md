# Palindrome Number (LeetCode)

## Problem

Given an integer **x**, return **true** if the integer is a **palindrome**, and **false** otherwise.

A number is a palindrome if it reads the same **forward and backward**.

### Example

Input

```
x = 121
```

Output

```
true
```

Input

```
x = -121
```

Output

```
false
```

---

## Approach

We reverse the digits of the number and compare it with the original number.

### Steps

1. Store the original number in a variable (`dup`).
2. Extract the last digit using `x % 10`.
3. Build the reversed number by multiplying the current reverse by `10` and adding the digit.
4. Reduce the number using `x / 10`.
5. After reversing, compare the reversed number with the original number.
6. If both are equal, the number is a **palindrome**.

---

## C++ Implementation

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int ld=0;
        int rev=0;
        int dup=x;
       while(x>0){
        ld=x%10;
        if(rev>INT_MAX/10 || rev<INT_MIN/10){
            return 0;
        }
        rev=(rev*10)+ld;
        x=x/10;

       } 
       if(rev==dup){
        return true;
       }
       else{
        return false;
       }
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

## Key Idea

A palindrome number remains the same when its digits are **reversed**, so we simply reverse the number and compare it with the original.
