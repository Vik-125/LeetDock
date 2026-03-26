class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hmap;
        int n = nums.size();

        for(int i=0;i<n;i++){
            hmap.insert({nums[i],i});
            int t = target - nums[i];
            if(hmap.find(t) != hmap.end() && hmap[t] != i){
                return {hmap[t],i};
            }
        }
        return {};
    }
};