class Solution {
public:
    int add(vector<int>& nums,int n)
    {
        int s = 0;
        for(auto it : nums)
        {
            s+=it;
        }
        return s;
    }
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = add(nums,n);
        int part = 0;
        int dupSum = 0;

        for(int i=0;i<n-1;i++)
        {
            dupSum += nums[i];
            sum -= nums[i];
            if((sum - dupSum)%2 == 0) part++;
        }
        return part;
    }
};