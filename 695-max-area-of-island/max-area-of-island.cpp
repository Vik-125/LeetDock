class Solution {
public:
    int dfs(int row,int col,vector<vector<int>> &grid,int n,int m,int deltaCol[],int deltaRow[])
    {
        grid[row][col] = -1;
        int area = 1;
        for(int i=0;i<4;i++)
        {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && grid[nrow][ncol] == 1)
            {   
                area += dfs(nrow,ncol,grid,n,m,deltaCol,deltaRow);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        int deltaRow[] = {0,-1,0,1};
        int deltaCol[] = {-1,0,1,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = dfs(i,j,grid,n,m,deltaCol,deltaRow);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};