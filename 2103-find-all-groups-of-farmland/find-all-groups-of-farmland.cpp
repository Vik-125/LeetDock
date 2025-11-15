class Solution {
public:
    void dfs(int i,int j,int R,int C,vector<vector<int>> &land,vector<vector<bool>>& vis,int &er,int &ec,int drow[],int dcol[])
    {
        vis[i][j] =  true;
        er = max(i,er);
        ec = max(j,ec);
        for(int k=0;k<4;k++)
        {
            int nr = i + drow[k];
            int nc = j + dcol[k];
            if(nr >= 0 && nc >= 0 && nr < R && nc < C && !vis[nr][nc] && land[nr][nc] == 1)
            {
                dfs(nr,nc,R,C,land,vis,er,ec,drow,dcol);
            }
        }
        return;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> vis (n,vector<bool>(m,false));
        vector<vector<int>> ans;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && land[i][j] == 1)
                {
                    int er = i;
                    int ec = j;
                    dfs(i,j,n,m,land,vis,er,ec,drow,dcol);
                    ans.push_back({i,j,er,ec});
                }
            }
        }
        return ans;
    }
};