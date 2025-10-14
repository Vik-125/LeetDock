class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(auto it : nums)
        {
            if(++hash[it] > 1) return it;
        }
        return -1;
    }
};