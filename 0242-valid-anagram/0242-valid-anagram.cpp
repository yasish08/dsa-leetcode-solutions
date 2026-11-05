class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int>freq1(256);
       vector<int>freq2(256);
       for(char ch:s){
        freq1[ch]++;
       }
       for(char ch:t){
        freq2[ch]++;
       }
       if(freq1==freq2){
        return true;
       }
       return false;
    }
};