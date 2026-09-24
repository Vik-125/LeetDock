class Solution {
public:
    int check(int m){
        int sum = 0;
        while(m > 0){
            sum += m%10;
            m /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] > 9 && check(nums[i]) == i){
                return i;
            }
            else if(nums[i] <= 9 && i == nums[i]) return i;
        }
        return -1;
    }
};