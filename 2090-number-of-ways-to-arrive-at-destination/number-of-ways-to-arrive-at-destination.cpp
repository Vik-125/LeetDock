class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

        vector<int> ways(n,0);
        ways[0] = 1;
        vector<long long> dist(n,LLONG_MAX);
        dist[0] = 0;

        pq.push({0,0});

        int mod = (int)(1e9 + 7);

        while(!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            long long dis = it.first;
            pq.pop();

            for(auto it : adj[node])
            {
                int neighbour = it.first;
                long long eWeight = it.second;

                if(dis + (long long)eWeight < dist[neighbour])
                {
                    dist[neighbour] = eWeight + dis;
                    pq.push({dist[neighbour],neighbour});
                    ways[neighbour] = ways[node];
                }
                else if(dis + (long long)eWeight == dist[neighbour])
                {
                    ways[neighbour] = (ways[neighbour] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};