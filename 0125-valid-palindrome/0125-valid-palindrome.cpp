class Solution {
public:
    bool isPalindrome(string s) {
        string temp ="";
        for(int i = 0; i < s.size(); i++) {
          if(isalnum(s[i])) {
            temp+=tolower(s[i]);
          }
        }
        int low=0;
        int high=temp.size()-1;
        while(low<high){
            if(temp[low]!=temp[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};