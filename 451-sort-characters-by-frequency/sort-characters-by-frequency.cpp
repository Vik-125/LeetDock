class Solution {
public:
    string frequencySort(string s) {
        string result = "";

        unordered_map<char, int> hash;
        for(auto &it : s){
            hash[it]++;
        }

        priority_queue<pair<int, char>> q;
        for(const auto &it  : hash){
            q.push({it.second, it.first});
        }

        while(!q.empty()){
            auto it = q.top();
            q.pop();
            for(int i=0;i<it.first;i++) result += it.second;
        }
        return result;
    }
};