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
