class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int n = nums.size();
        for (int i = 1; i <= nums.size() - 1; i++) {
            if(i == n-1){
                if(nums[i-1] < nums[i]) return i;
                break;
            }
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
                return i;
        }
        return 0;
    }
};