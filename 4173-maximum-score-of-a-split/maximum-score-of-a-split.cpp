class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> preSum(n);
        vector<int> sufMin(n);

        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            preSum[i] = sum;
        }

        int mini = INT_MAX;
        for(int i=n-1;i>0;i--){
            mini = min(nums[i],mini);
            sufMin[i-1] = mini;
        }
        sufMin[0] = mini;

        long long maxi = INT_MIN;
        for(int i=0;i<n-1;i++){
            long long sc = preSum[i] - sufMin[i];
            maxi = max(maxi,sc);
        }
        return maxi;
    }
};