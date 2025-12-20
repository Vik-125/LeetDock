class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int cnt = 0;
        long long res = 0;
        int zero = 0;

        if(nums.size() == 1) return nums[0];
        for(auto it : nums)
        {
            if(it < 0) cnt++;
            if(it == 0) zero++;
        }
        if(zero == nums.size()) return 0;

        if(cnt % 2 == 0)
        {
            res = 1;
            for(auto it : nums)
            {
                if(it == 0) continue;
                res = res * it;
            }
            return res;
        }
        else
        {
            sort(nums.begin(),nums.end());
            long long mid = 1;
            int c = 0;
            for(int i=0;i<nums.size();i++)
            {
                if(i == cnt - 1) continue;
                if(nums[i] == 0) continue;
                mid *= nums[i];
                c++;
            }
            if(mid == 1 && c == 0) return res;
            else return mid;
        }
        return res;
    }
};