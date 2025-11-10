class Solution {
public:
    void dfs(int r,int c,int R,int C,vector<vector<char>> board,vector<vector<int>> &vis)
    {
        vis[r][c] = 1;

        if(r+1 < R && !vis[r+1][c] && board[r+1][c] == 'X')
        {
            dfs(r+1,c,R,C,board,vis);
        }
        if(c+1 < C && !vis[r][c+1] && board[r][c+1] == 'X')
        {
            dfs(r,c+1,R,C,board,vis);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j] == 'X')
                {
                    cnt++;
                    dfs(i,j,n,m,board,vis);
                }
            }
        }
        return cnt;
    }
};