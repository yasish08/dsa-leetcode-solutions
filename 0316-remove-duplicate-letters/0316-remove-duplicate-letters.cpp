class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        for(char ch : s)
            freq[ch - 'a']++;

        for(char ch : s) {
            freq[ch - 'a']--;

            if(used[ch - 'a'])
                continue;

            while(!st.empty() &&
                  st.top() > ch &&
                  freq[st.top() - 'a'] > 0) {
                used[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            used[ch - 'a'] = true;
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};