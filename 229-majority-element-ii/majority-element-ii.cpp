class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> hash;
        vector<int> ans;

        for(auto it : nums){
            hash[it]++;
        }
        for(auto it : hash){
            if(it.second > n/3) ans.push_back(it.first);
        }
        return ans;
    }
};