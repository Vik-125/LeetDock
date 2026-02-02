class Solution {
public:
    bool dfs(int r,int c, vector<vector<bool>>& vis2,int delr[],int delc[],int R,int C,vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        vis2[r][c] = 1;
        bool isSubIsland = (grid1[r][c] == 1);
        for(int i=0;i<4;i++)
        {
            int row = r + delr[i];
            int col = c + delc[i];

            if(row < R && row >= 0 && col < C && col >= 0 && !vis2[row][col] && grid2[row][col] == 1)
            {
                if(!dfs(row,col,vis2,delr,delc,R,C,grid1,grid2))
                {
                    isSubIsland = false;
                }
            }
        }
        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int ans = 0;
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<bool>> vis2(n,vector<bool> (m,false));

        int delr[] = {-1,0,1,0};
        int delc[] = {0,-1,0,1};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis2[i][j] && grid2[i][j] == 1)
                {
                    if(dfs(i,j,vis2,delr,delc,n,m,grid1,grid2))
                    {
                        ans++;
                    }
                }

            }
        }
        return ans;
    }
};