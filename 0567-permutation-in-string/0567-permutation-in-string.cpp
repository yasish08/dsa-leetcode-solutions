class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
       unordered_map<char,int>mp1;
       for(int i=0;i<s1.size();i++){
        mp1[s1[i]]++;
       } 
       unordered_map<char,int>mp2;
       for(int i=0;i<s1.size();i++){
        mp2[s2[i]]++;
       }
       if(mp1==mp2){
        return true;
       }
       for(int i=s1.size();i<s2.size();i++){
           char outgoing=s2[i-s1.size()];
           mp2[outgoing]--;
           if(mp2[outgoing]==0){
            mp2.erase(outgoing);
           }
           mp2[s2[i]]++;
           if(mp1==mp2){
            return true;
           }
       }
       return false;
    }
};