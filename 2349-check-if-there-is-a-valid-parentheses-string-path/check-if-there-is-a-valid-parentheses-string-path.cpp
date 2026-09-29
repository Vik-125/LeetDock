class Solution {
public:
    int dp[101][101][205];
    bool dfs(vector<vector<char>>& grid, int n, int m, int brackets, int r, int c){
        if(r >= n || c >= m) return false;  

        grid[r][c] == ')' ? brackets-- : brackets++;

        if(brackets < 0) return false;

        if(dp[r][c][brackets] != -1){
            return dp[r][c][brackets];
        }      

        if(r == n-1 && c == m-1){
            return brackets == 0;
        }

        bool down = dfs(grid, n, m ,brackets, r+1, c); 
        bool right = dfs(grid, n, m ,brackets, r, c+1);


        return dp[r][c][brackets] = (down || right);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int brackets = 0;
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;

        memset(dp,-1, sizeof(dp));
        return dfs(grid, n, m, brackets, 0, 0);
    }
};