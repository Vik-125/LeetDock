class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int minDis = INT_MAX;
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(minDis > abs(target - sum)){
                    minDis = min(minDis,abs(target - sum));
                    ans = sum;
                    cout << ans << " ";
                }

                if(sum > target){
                    k--;
                    //while(j < k && nums[k] == nums[k-1]) k--;
                }
                else if(sum < target){
                    j++;
                    //while(j < k && nums[j] == nums[j+1]) j++;
                }
                else return sum;
            }
        }
        return ans;
    }
};