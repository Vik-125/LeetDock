class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int ans = 1;
        int cnt = 0;

        int prev = INT_MIN;
        sort(nums.begin(),nums.end());

        for(auto it : nums){
            if(it == (prev+1)){
                prev = it;
                cnt++;
                ans = max(ans,cnt);
            }
            if(it == prev) continue;
            else{
                prev = it;
                cnt = 1;
            }
        }
        return ans;
    }
};