class Solution {
public:
    void find(vector<vector<int>> &subs, vector<int> &temp, vector<int> &nums, int i){
        if(i >= nums.size()){
            subs.push_back(temp);
            return;
        }

        find(subs, temp, nums, i+1);
        temp.push_back(nums[i]);
        find(subs, temp, nums, i+1);
        temp.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> temp;
        find(subs, temp, nums, 0);
        return subs;
    }
};