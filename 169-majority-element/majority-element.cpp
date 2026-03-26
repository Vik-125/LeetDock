class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int maj = nums[0];

        for(auto it : nums){
            if(it == maj) cnt++;
            else if(it != maj){
                cnt--;
                if(cnt == 0){
                    maj = it;
                    cnt = 1;
                }
            }
        }
        return maj;
    }
};