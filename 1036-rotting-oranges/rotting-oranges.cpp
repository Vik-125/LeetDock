class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();

        if(n == 0) return 0;

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(!q.empty())
        {
            int s = q.size();
            bool changed = 0;
            for(int j=0;j<s;j++)
            {
                auto it = q.front();
                int r = it.first;
                int c = it.second;
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int nr = delr[i] + r;
                    int nc = delc[i] + c;

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        changed = 1;
                    }
                }
            }
            if(changed) time++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};