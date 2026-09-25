class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();

        int zeroCnt = 0;
        int oneCnt = 0;
        int cnt = 0;
        while(j < n){
            if(nums[j] == 1){
                oneCnt++;
            }
            if(nums[j] == 0) zeroCnt++;
            if(zeroCnt > k){
                while(i < n){
                    if(nums[i] == 1){
                        oneCnt--;
                    }
                    else if(nums[i] == 0){
                        zeroCnt--;
                        i++;
                        break;
                    }
                    i++;
                }
            }
            j++;
            cnt = max(cnt, oneCnt + zeroCnt);
        }
        return cnt;
    }
};