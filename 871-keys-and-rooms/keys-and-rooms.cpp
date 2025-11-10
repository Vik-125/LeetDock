class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> visited;
        int V = rooms.size();

        q.push(0);
        visited.insert(0);

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

                for(auto it : rooms[i])
                {
                    if(visited.find(it) == visited.end())
                    {
                        visited.insert(it);
                        q.push(it);
                    }
                }
        }
        return visited.size() == V;
    }
};