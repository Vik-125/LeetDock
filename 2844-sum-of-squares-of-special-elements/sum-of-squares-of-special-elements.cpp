class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        
        for(int i=0;i<n;i++){
            if(n % (i+1) == 0){
                result += pow(nums[i],2);
            }
        }
        return result;
    }
};