class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
       for(int neighbor:adj[node]){
        if(!vis[neighbor]){
           if(dfs(neighbor,adj,vis,pathvis)){
            return true;
           }
        }
        else if(pathvis[neighbor]==1){
            return true;

        }
       }
       pathvis[node]=0;
       return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
               if(dfs(i,adj,vis,pathvis)){
                return false;
               }
            }
        }
        return true;
    }
};