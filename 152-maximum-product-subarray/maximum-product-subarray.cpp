class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size()-1;
        //if(n == 0) return nums[0];
        long long maxPro = INT_MIN;
        long long sufPro = 1;
        long long prePro = 1;

        for(int i=0;i<=n;i++){
            if(prePro == 0) prePro = 1;
            if(sufPro == 0) sufPro = 1;

            prePro *= nums[n - i];
            sufPro *= nums[i];

            maxPro = max({maxPro,prePro,sufPro});
        }
        return maxPro;
    }
};