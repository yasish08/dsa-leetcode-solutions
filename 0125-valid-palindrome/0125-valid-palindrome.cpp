class Solution {
public:
    bool isPalindrome(string s) {
        
        string temp = "";
        

    for(int i = 0; i < s.size(); i++) {
       if(isalnum(s[i])) {
         temp += tolower(s[i]);
        }
    }
    string original=temp;
        int left=0;
        int right=original.size()-1;
        while(left<right){

            swap(original[left],original[right]);
            left++;
            right--;
        }
        if(temp==original){
            return true;
        }
        return false;
    }
};