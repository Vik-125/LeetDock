class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int p = 0;
        int l = 0;
        int n = nums.size();
        unordered_map<int,int> hash;

        int length = 0;
        while(p < n){
            int m = nums[p];
            hash[m]++;
            if(hash[m] > k){
                while(hash[m] > k && l <= p){
                    hash[nums[l]]--;
                    l++;
                }
            }
            else length = max(length, p-l+1);
            p++;
        }
        return length;
    }
};