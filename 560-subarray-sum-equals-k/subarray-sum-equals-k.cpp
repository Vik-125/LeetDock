class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;

        unordered_map<int,int> hash;
        hash[0]++;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = sum - k;
            ans += hash[rem];
            hash[sum]++;
        }
        return ans;
    }
};