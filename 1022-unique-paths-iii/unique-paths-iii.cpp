class Solution {
public:
    int find(int r, int c, int R, int C, int n, int m,
             vector<vector<int>>& grid, int vis, int& z) {
        if (r >= n || c >= m || r < 0 || c < 0)
            return 0;
        if (grid[r][c] == -1)
            return 0;
        if (r == R && c == C)
            return vis == z ? 1 : 0;
        
        int temp = grid[r][c];
        grid[r][c] = -1;
        int up = find(r - 1, c, R, C, n, m, grid, vis + 1, z);
        int down = find(r + 1, c, R, C, n, m, grid, vis + 1, z);
        int left = find(r, c - 1, R, C, n, m, grid, vis + 1, z);
        int right = find(r, c + 1, R, C, n, m, grid, vis + 1, z);
        grid[r][c] = temp;
        return (left + right + up + down);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int r = 0;
        int c = 0;
        int R = 0;
        int C = 0;
        int zeroes = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    r = i;
                    c = j;
                }
                if (grid[i][j] == 0)
                    zeroes++;
                if (grid[i][j] == 2) {
                    R = i;
                    C = j;
                }
            }
        }
        zeroes += 2; //(for starting & ending)
        int vis = 1;
        return find(r, c, R, C, n, m, grid, vis, zeroes);
    }
};