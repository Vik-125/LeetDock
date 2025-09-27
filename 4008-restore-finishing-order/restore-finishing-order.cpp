class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        unordered_map<int,int> hash;

        for(int it : friends)
        {
            hash[it]++;
        }
        for(int it : order)
        {
            if(hash.count(it)){
                ans.push_back(it);
            }
        }
        return ans;
    }
};