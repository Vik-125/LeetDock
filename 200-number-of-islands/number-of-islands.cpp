class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>& vis,int drow[],int dcol[],int rows,int cols)
    {
        vis[row][col] = true;

        for(int i=0;i<4;i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < rows && ncol < cols && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
            {
                dfs(nrow,ncol,grid,vis,drow,dcol,rows,cols);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        int count = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    count++;
                    dfs(i,j,grid,vis,drow,dcol,n,m);
                }
            }
        }

        return count;
    }
};