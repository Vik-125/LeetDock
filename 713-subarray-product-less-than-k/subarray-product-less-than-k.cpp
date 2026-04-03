class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        long long product = 1;
        long long n = nums.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            long long ans = 1;
            for(int j=i;j<n;j++){
                ans *= nums[j];

                if(ans < k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};