class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<int>freq(256,0);
        string ans="";
        vector<bool>used(256,false);
        for(char ch:s){
            freq[ch]++;
        }
        for(char ch:s){
            freq[ch]--;
            if(used[ch])
            continue;
            while(!st.empty()&&st.top()>ch&&freq[st.top()]>0){
                used[st.top()]=false;
                st.pop();
            }
            used[ch]=true;
            st.push(ch);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};