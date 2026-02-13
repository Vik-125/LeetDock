class Solution {
public:
    bool dfs(int i,int j,int R,int C,vector<vector<char>>& board,string word,int k,int p)
    {
        if(p == k) return true;
        if (i < 0 || j < 0 || i >= R || j >= C) return false;
        if(board[i][j] != word[p]) return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(i+1, j, R, C, board, word,k, p+1) ||
                     dfs(i-1, j, R, C, board, word,k, p+1) ||
                     dfs(i, j+1, R, C, board, word,k, p+1) ||
                     dfs(i, j-1, R, C, board, word,k, p+1);

        board[i][j] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int k = word.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(i,j,n,m,board,word,k,0)) return true;
                    else continue;
                }
                else continue;
            }
        }
        return false;
    }
};