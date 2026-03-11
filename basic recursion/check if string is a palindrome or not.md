# Palindrome Number

## Problem

Given an integer **x**, return **true** if **x** is a palindrome, and **false** otherwise.

A number is considered a palindrome if it reads the same **forward and backward**.

### Example

Input:

```id="ex1"
x = 121
```

Output:

```id="ex2"
true
```

Input:

```id="ex3"
x = 10
```

Output:

```id="ex4"
false
```

---

# Approach

To determine whether a number is a palindrome:

1. Store the original number in a variable `dup`.
2. Reverse the digits of the number using modulo `%` and division `/`.
3. Compare the reversed number with the original number.
4. If both are equal → the number is a palindrome.

An overflow check is included to ensure the reversed number does not exceed the **32-bit integer limit**.

---

# C++ Implementation

```cpp id="code1"
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

# Time Complexity

**O(log10 n)**
The number of digits in `n` determines the number of iterations.

---

# Space Complexity

**O(1)**
Only constant extra space is used.

---

# Key Idea

A palindrome number remains unchanged when its digits are reversed.
By reversing the number and comparing it with the original, we can determine whether it is a palindrome.
