class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int idx=0;
        while(i<chars.size()){
            int current=chars[i];
            int count=0;
            while(i<chars.size() && current==chars[i] ){
                count++;
                i++;
            }
            chars[idx]=current;
            idx++;
            if(count>1){
                string c=to_string(count);
                for(char ch:c){
                    chars[idx]=ch;
                    idx++;
                }
            }
        }
        return idx;
    }
};