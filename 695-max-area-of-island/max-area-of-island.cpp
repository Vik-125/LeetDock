class Solution {
public:
    void findArea(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c, int R, int C, int drow[], int dcol[], int &area){
        if(vis[r][c] || grid[r][c] == 0) return;

        vis[r][c] = true;

        for(int i=0;i<4;i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr >= 0 && nr < R && nc >= 0 && nc < C && !vis[nr][nc] && grid[nr][nc] == 1){
                area++;
                findArea(grid, vis, nr, nc, R, C, drow, dcol, area);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dcol[] = {0,1,0,-1};
        int drow[] = {1,0,-1,0};

        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int area = 0;
                if(!vis[i][j] && grid[i][j] == 1){
                    area++;
                    findArea(grid, vis, i, j, n, m, drow, dcol, area);
                }
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }
};