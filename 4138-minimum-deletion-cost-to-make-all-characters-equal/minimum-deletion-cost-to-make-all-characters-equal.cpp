class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]+=cost[i];
        }
        long long mcost=LLONG_MAX;
        long long totals=accumulate(cost.begin(),cost.end(),0LL);
        for(auto i:mp){
            mcost=min(mcost,totals-i.second);
        }
        return mcost;
    }
};