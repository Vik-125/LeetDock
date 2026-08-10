class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int n = nums.size();

        for(int i=0;i<n;i++){
            hash[nums[i]] = i;
        }

        for(int i=0;i<n;i++){
            int k = target - nums[i];
            if(hash[k] && hash[k] != i){
                return {i,hash[k]};
            }
        }
        return {};
    }
};