class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> hash;
        int maxFreq = 0;

        for(int it : nums)
        {
            hash[it]++;
            maxFreq = max(maxFreq,hash[it]);
        }

        vector<vector<int>> ans(maxFreq);
        vector<int> toErase;
        int count = 0;
        while(hash.size() > 0)
        {
            for(auto &[key,value] : hash)
            {
                ans[count].push_back(key);
                hash[key]--;
                if(hash[key] == 0) toErase.push_back(key);
            }
            for (int key : toErase) {
                hash.erase(key);
            }
            count++;
        }
        return ans;
    }
};