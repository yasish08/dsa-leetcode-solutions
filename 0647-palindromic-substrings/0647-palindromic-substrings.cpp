class Solution {
public:
    bool check(string s,int left,int right){
        
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
           
        }
        
        return true;
 
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            
            for(int j=i;j<s.size();j++){
                if(check(s,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
    
};