class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        map<int,int> hash;
        for(auto it : nums) hash[it]++;

        int f = 0;
        int s = 0;
        int i = 0;
        int freq = 0;
        for(auto it : hash)
        {
            if(i == 0)
            {
                f = it.first;
                freq = it.second;
                i++;
            }
            else if(it.second != freq)
            {
                s = it.first;
                break;
            }
        }
        if(s != 0) return {f,s};
        return {-1,-1};
    }
};