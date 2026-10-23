class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
           int required=target-nums[i];
           if(mp.find(required)!=mp.end()){
            ans.push_back(mp[required]);
            ans.push_back(i);
            return ans;
           }
           else{
              mp[nums[i]]=i;
           }
        }
        return ans;
    }
};