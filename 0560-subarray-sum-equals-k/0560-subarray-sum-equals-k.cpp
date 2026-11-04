class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        int currsum=0;
        int prevsum=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            prevsum=currsum-k;
            if(mp.find(prevsum)!=mp.end()){
               cnt+=mp[prevsum];
            }
            mp[currsum]++;
        }
        return cnt;
    }
};