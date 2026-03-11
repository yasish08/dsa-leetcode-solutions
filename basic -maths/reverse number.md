# Reverse Integer (LeetCode)

## Problem

Given a signed **32-bit integer `x`**, return `x` with its digits reversed.

If reversing `x` causes the value to go outside the **signed 32-bit integer range**
`[-2^31, 2^31 - 1]`, then return `0`.

---

## Example

### Example 1

**Input**

```id="revex1"
x = 123
```

**Output**

```id="revex2"
321
```

---

### Example 2

**Input**

```id="revex3"
x = -123
```

**Output**

```id="revex4"
-321
```

---

### Example 3

**Input**

```id="revex5"
x = 120
```

**Output**

```id="revex6"
21
```

---

## Approach

1. Extract the last digit using `x % 10`.
2. Multiply the reversed number by `10`.
3. Add the extracted digit.
4. Reduce the number using `x / 10`.
5. Before updating the reversed number, check for **integer overflow**.
6. If overflow happens, return `0`.

---

## C++ Solution

```cpp id="revcode"
// Problem: Reverse Integer
// Platform: LeetCode
// Approach: Extract digits using modulo and build reversed number
// Time Complexity: O(log10 n)
// Space Complexity: O(1)

class Solution {
public:
    int reverse(int x) {
        long long reverse = 0;
        long long ld = 0;

        while(x != 0){
            ld = x % 10;

            if(reverse > INT_MAX/10 || reverse < INT_MIN/10)
                return 0;

            reverse = (reverse * 10) + ld;
            x = x / 10;
        }

        return reverse;
    }
};
```

---

## Time Complexity

```id="revtime"
O(log10 n)
```

The loop runs once for every digit in the number.

---

## Space Complexity

```id="revspace"
O(1)
```

No additional space is used.

---

## Key Idea

The main idea is to **extract digits one by one using modulo (`%`) and rebuild the number in reverse order**, while ensuring the reversed number does not overflow the **32-bit integer limit**.
