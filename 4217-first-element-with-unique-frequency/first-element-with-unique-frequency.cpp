class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hash;
        for(auto it : nums) hash[it]++;

        unordered_map<int,int> hash2;
        for(auto &it : hash) hash2[it.second]++;

        for(int i : nums)
        {
            if(hash2[hash[i]] == 1) return i;
        }
        return -1;
    }
};