class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> hash;

        for(int i=0;i<n;i++){
            int complement = target - nums[i];
            if(hash.find(complement) != hash.end()){
                return {i, hash[target - nums[i]]};
            }
            hash[nums[i]] = i;
        }
        
        return {};
    }
};