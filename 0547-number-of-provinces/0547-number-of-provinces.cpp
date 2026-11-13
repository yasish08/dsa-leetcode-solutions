class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>&vis,int node){
       vis[node]=1;
       for(int i=0;i<isConnected.size();i++){
        if(isConnected[node][i]==1&&!vis[i]){
            dfs(isConnected,vis,i);
        }
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>vis(isConnected.size(),0);
        int cnt=0;
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                cnt++;
                dfs(isConnected,vis,i);
            }
        }
        return cnt;
    }
};