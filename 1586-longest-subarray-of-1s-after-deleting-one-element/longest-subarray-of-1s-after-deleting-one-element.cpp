class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        int cnt = 0;
        bool flag = true;
        int maxSub = 0;
        while(j < n){
            if(nums[j] == 1) cnt++;
            if(!flag && nums[j] != 1){
                while(i < n){
                    if(nums[i] == 0){
                        flag = true;
                        i++;
                        break;
                    }
                    else cnt--;
                    i++;
                }
                continue;
            }
            else if(nums[j] != 1){
                flag = false;
            }
            j++;
            maxSub = max(maxSub, cnt);
        }
        if(maxSub == n) return n-1;
        return maxSub;
    }
};