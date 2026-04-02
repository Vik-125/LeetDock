class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int r = nums.size()-1;
        int l = 0;
        int sum = 0;
        int ans = INT_MIN;
        while(l <= r){
            sum = nums[l] + nums[r];
            ans = max(ans,sum);
            l++;
            r--;
        }
        return ans;
    }
};