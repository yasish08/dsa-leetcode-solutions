class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<int,int>mp1;
        for(int i=0;i<p.size();i++){
           mp1[p[i]]++;
        }
        unordered_map<int,int>mp2;
        for(int i=0;i<p.size();i++){
            mp2[s[i]]++;
            if(mp1==mp2){
                ans.push_back(i-p.size()+1);
            }
        }
        for(int i=p.size();i<s.size();i++){
            char outgoing=s[i-p.size()];
            mp2[outgoing]--;
            if(mp2[outgoing]==0){
                mp2.erase(outgoing);
            }
            mp2[s[i]]++;
            if(mp1==mp2){
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};