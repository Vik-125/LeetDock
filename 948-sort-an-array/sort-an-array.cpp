class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans = nums;
        return ans;
    }
};