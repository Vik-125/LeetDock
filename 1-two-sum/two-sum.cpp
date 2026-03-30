class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hmap;
        int n = nums.size();

        for(auto it : nums) hmap[it]++;

        for(int i=0;i<n;i++){
            int rem = target - nums[i];
            if(find(nums.begin(),nums.end(),rem) != nums.end() && (find(nums.begin(),nums.end(),rem) - nums.begin()) != i){
                int ind = find(nums.begin(),nums.end(),rem) - nums.begin();
                return {i,ind};
            }
        }
        return {};
    }
};