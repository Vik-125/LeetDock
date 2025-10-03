class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto it: nums)
        {
            if(hash.count(it)) return true;
            hash[it]++;
        }
        return false;
    }
};