class Solution {
public:
    int find(int i, vector<int>& nums, int target, int sum) {
        if (i == nums.size()) {
            if (sum == target)
                return 1;
            else
                return 0;
        }

        return (find(i + 1, nums, target, sum + nums[i]) +
                find(i + 1, nums, target, sum - nums[i]));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return find(0, nums, target, 0);
    }
};