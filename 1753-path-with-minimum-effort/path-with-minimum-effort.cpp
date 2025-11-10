class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>> >,
        greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto it = pq.top();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();

            if(r == n-1 && c == m-1) return dist[r][c];
            // r-1,c
            // r,c+1
            // r+1,c
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int R = r + drow[i];
                int C = c + dcol[i];
                if(R < n && R >= 0 && C < m && C >= 0)
                {
                    int newEffort = max(abs(heights[r][c] - heights[R][C]),diff);
                    if(newEffort < dist[R][C])
                    {
                        dist[R][C] = newEffort;
                        pq.push({dist[R][C],{R,C}});
                    }
                }
            }
        }
        return -1;
    }
};