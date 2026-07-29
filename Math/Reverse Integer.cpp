class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        long long ld=0;
        while(x!=0){
            ld=x%10;
            if(rev> INT_MAX/10 || rev < INT_MIN/10)
                return 0;
            rev=(rev*10)+ld;
            x=x/10;
        } 
        return rev; 
    }
};