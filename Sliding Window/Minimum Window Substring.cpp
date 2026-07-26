class Solution {
public:
    string minWindow(string s, string t) {
        int mini=INT_MAX;
        int start=-1;
        vector<int>tfreq(256,0);
        for(char c:s){
            tfreq[c]++;
        }
        for(int i=0;i<s.length();i++){
            vector<int> sfreq(256,0);
            for(int j=i;j<s.length();j++){
                sfreq[s[j]]++;
                bool valid=true;
            if(sfreq<=tfreq){
                valid=false;
            }
            if(valid ){
                int len=j-i+1; 
                if(len<mini){
                mini=len;
                start=i;

            }
            }
            
            }
          
            
        }
        if(start==-1){
            return " ";
        }
        return s.substr(start,mini);
    }
};