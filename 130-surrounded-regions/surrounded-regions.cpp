class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<bool>>& vis,int drow[],int dcol[],int rows,int cols)
    {
        vis[r][c] = true;

        for(int i=0;i<4;i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow < rows && nrow >= 0 && ncol < cols && ncol >= 0 && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                dfs(nrow,ncol,board,vis,drow,dcol,rows,cols);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int drow[] = {0,-1,0,1};
        int dcol[] = {1,0,-1,0};

        for(int j=0;j<m;j++)
        {
            // first row
            if(board[0][j] == 'O' && !vis[0][j])
            {
                dfs(0,j,board,vis,drow,dcol,n,m);
            }
            // last row
            if(board[n-1][j] == 'O' && !vis[n-1][j])
            {
                dfs(n-1,j,board,vis,drow,dcol,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            // first column
            if(board[i][0] == 'O' && !vis[i][0])
            {
                dfs(i,0,board,vis,drow,dcol,n,m);
            }
            // last column
            if(board[i][m-1] == 'O' && !vis[i][m-1])
            {
                dfs(i,m-1,board,vis,drow,dcol,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};