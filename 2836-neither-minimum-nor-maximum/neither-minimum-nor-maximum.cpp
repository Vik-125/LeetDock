class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() <= 2) return -1;
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        for(int i=0;i<3;i++){
            if(mini != nums[i] && maxi != nums[i]) return nums[i];
        }
        return 0;
    }
};