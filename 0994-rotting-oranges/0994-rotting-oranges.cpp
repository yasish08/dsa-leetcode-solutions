class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        int min=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                  q.push({i,j});
                }
                else if(grid[i][j]==1){
                  fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        while(!q.empty()){
            int sz=q.size();
            bool rottenthismin=false;
            for(int i=0;i<sz;i++){
                 auto[row,col]=q.front();
                 q.pop();
                vector<int> dr={-1,1,0,0};
                vector<int>dc={0,0,-1,1};
                for(int i=0;i<4;i++){
                    int nr=row+dr[i];
                    int nc=col+dc[i];
                    if(nr>=0&&nr<n&&nc>=0&&nc<m){
                      if(grid[nr][nc]==1){
                       grid[nr][nc]=2;
                       fresh--;
                       q.push({nr,nc});
                       rottenthismin=true;
                       }
                    }
                }
            }
            if(rottenthismin){
               min++;
            }
        }
        if(fresh==0){
            return min;
        }
        else{
            return -1;
        }
    }
};