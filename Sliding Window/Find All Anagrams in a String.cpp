class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.length();
        int k=p.length();
        vector<int> pfreq(26,0);
        vector<int> window(26,0);
        if(k>n){
            return ans;
        }
        for(char c:p){
            pfreq[c-'a']++;
        }
        for(int i=0;i<k;i++){
            window[s[i]-'a']++;
        }
        if(pfreq==window){
            ans.push_back(0);
        }
        for(int i=k;i<n;i++){
            window[s[i]-'a']++;
            window[s[i-k]-'a']--;
            if(pfreq==window){
                ans.push_back(i-k+1);
            }

        }
        return ans;

    }
};