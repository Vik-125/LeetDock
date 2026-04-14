class Solution {
public:
    void find(int sum,vector<int>& nums,int target,int i,int &cnt){
        if(i == nums.size()){
            if(sum == target) cnt++;
            return;
        }
        sum += nums[i];
        find(sum,nums,target,i+1,cnt);

        sum -= (nums[i]+nums[i]);
        find(sum,nums,target,++i,cnt);
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt = 0;
        find(0,nums,target,0,cnt);
        return cnt;
    }
};