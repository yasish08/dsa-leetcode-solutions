class Solution {
public:
    bool checkInclusion(string s1, string 
    s2) {
        vector<int> pfreq(26,0);
        vector<int> window(26,0);
        int k=s1.length();
        int n=s2.length();
        if(k>n){