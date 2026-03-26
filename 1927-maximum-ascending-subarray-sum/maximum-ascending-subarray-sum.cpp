class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int prev = -1;
        int maxi = INT_MIN;

        for(auto it : nums){
            if(it > prev){
                sum += it;
                maxi = max(maxi,sum);
            }
            else{
                sum = it;
            }
            prev = it;
        }
        return maxi;
    }
};