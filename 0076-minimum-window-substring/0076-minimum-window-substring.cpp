class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int required=t.size();
        int mini=INT_MAX;
        int start=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0){
                required--;
            }
            mp[s[i]]--;
            while(required==0){
                if(i-j+1<mini){
                    mini=i-j+1;
                    start=j;
                }
                mp[s[j]]++;
                if(mp[s[j]]>0){
                    required++;
                }
                j++;
            }
        }
        if(mini==INT_MAX){
            return "";
        }
        return s.substr(start,mini);
    }
};