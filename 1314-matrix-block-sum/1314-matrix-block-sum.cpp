class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>>ans(r,vector<int>(c));
        vector<vector<int>>prefix(r+1,vector<int>(c+1,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                prefix[i+1][j+1]=mat[i][j]+prefix[i][j+1]+prefix[i+1][j]-prefix[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int startrow=max(0,i-k);
                int endrow=min(r-1,i+k);
                int startcol=max(0,j-k);
                int endcol=min(c-1,j+k);
                ans[i][j]=prefix[endrow+1][endcol+1]-prefix[startrow][endcol+1]-prefix[endrow+1][startcol]+prefix[startrow][startcol];
            }
        }
        return ans;
    }
};