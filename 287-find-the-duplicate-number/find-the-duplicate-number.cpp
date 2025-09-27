class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(auto it : nums)
        {
            hash[it]++;
        }

        for(auto &[key,value] : hash)
        {
            if(value > 1) return key;
        }
        return -1;
    }
};