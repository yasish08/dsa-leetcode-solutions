class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int row,int col){
        vis[row][col]=1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc= col+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                if(grid[nr][nc]=='1'&&!vis[nr][nc]){
                    dfs(grid,vis,nr,nc);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
              if(grid[i][j]=='1'&&!vis[i][j]){
                cnt++;
                dfs(grid,vis,i,j);
               }
            }
        }
        return cnt;
    }
};