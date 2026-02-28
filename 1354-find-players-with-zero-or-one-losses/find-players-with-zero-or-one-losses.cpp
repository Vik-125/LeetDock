class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       map<int,pair<int,int>> hash;

       for(auto it : matches)
       {
            hash[it[0]].first++;
            hash[it[1]].second++;
       }

       vector<vector<int>> ans(2);
       for(auto it : hash)
       {
            int wins = it.second.first;
            int loss = it.second.second;
            int player = it.first;
            if(loss == 0 && wins > 0) {
                ans[0].push_back(player);
            }
            if(loss == 1) {
                ans[1].push_back(player);
            }
       }
       return ans;
    }
};