class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &grid,int &count,int deltaRow[],int deltaCol[])
    {
        int n = grid.size();
        int m = grid[0].size();
        grid[row][col] = -1;
        for(int i=0;i<4;i++)
        {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= m || grid[nrow][ncol] == 0) {
                count++;
            }
            else if (grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, count, deltaRow, deltaCol);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int deltaRow[] = {-1,0,1,0};
        int deltaCol[] = {0,1,0,-1};
        for(int i=0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,grid,count,deltaRow,deltaCol);
                }
            }
        }

        return count;
    }
};