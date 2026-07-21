class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> pfreq(26,0);
        vector<int> window(26,0);
        int k=s1.length();
        int n=s2.length();
        if(k>n){
            return false;
        }
        for(char c:s1){
            pfreq[c-'a']++;
        }
        for(int i=0;i<k;i++){
            window[s2[i]-'a']++;
        }
        if (pfreq==window){
            return true;
        }
        for(int i=k;i<n;i++){
            window[s2[i]-'a']++;
            window[s2[i-k]-'a']--;
            if (pfreq==window){
            return true;
            }
        }
        

        return false;
    }
};