class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        vector<vector<int>>dis(mat.size(),vector<int>(mat[0].size(),-1));
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
                while(!q.empty()){
                    auto[row,col]=q.front();
                    q.pop();
                    vector<int>dr={-1,1,0,0};
                    vector<int>dc={0,0,-1,1};
                    for(int i=0;i<4;i++){
                       int nr=row+dr[i];
                       int nc=col+dc[i];
                       if(nr>=0&&nr<n&&nc>=0&&nc<m&&dis[nr][nc]==-1){
                          dis[nr][nc]=dis[row][col]+1;
                          q.push({nr,nc});
                       }
                    }
                }
        return dis;
    }
};