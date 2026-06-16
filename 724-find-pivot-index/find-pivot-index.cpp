class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // int total = accumulate(nums.begin(), nums.end(), 0);
        // int leftSum = 0;
        // for (int i = 0; i < nums.size(); ++i) {
        //     if (leftSum == total - leftSum - nums[i])
        //         return i;
        //     leftSum += nums[i];
        // }
        // return -1;
        vector<int> prefixSum(nums.size(),0);
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            prefixSum[i] = sum;
        }
        for(int i=0;i<nums.size();i++){
            if(prefixSum[i] - nums[i] == sum - prefixSum[i]) return i;
        }
        return -1;
    }
};