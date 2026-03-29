class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int sum = 0;

        unordered_map<int,int> sumHash;
        sumHash[0] = 1;

        for(auto it : nums){
            sum += it;

            long long rem = sum - k;
            if(sumHash.find(rem) != sumHash.end()){
                ans += sumHash[rem];
            }
            sumHash[sum]++;
        }
        return ans;
    }
};