class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        int cnt = 0;

        for(const auto &it : prerequisites)
        {
            int a = it[0],b = it[1];
            adj[b].push_back(a);

            indegree[a]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;
            for(const auto &it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return numCourses == cnt;
    }
};