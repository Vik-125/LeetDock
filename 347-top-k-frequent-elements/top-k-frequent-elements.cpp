class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int,int>> q;
        unordered_map<int,int> hash;

        for(auto it : nums){
            hash[it]++;
        }
        for(const auto &it : hash){
            q.push({it.second, it.first});
        }
        for(int i=0;i<k;i++){
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};