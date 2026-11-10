class Solution {
public:
    void dfs(vector<vector<int>>image,vector<vector<int>>&vis,int row,int col,int originalcolor){
        int n=image.size();
        int m=image[0].size();
        vis[row][col]=1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                if(!vis[nr][nc]&&image[nr][nc]==originalcolor){
                    dfs(image,vis,nr,nc,originalcolor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int originalcolor=image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(image,vis,sr,sc,originalcolor);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1){
                    image[i][j]=color;
                }
            }
        }
        return image;
    }
};