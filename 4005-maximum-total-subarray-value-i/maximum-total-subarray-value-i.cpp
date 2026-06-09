class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return (long long)(*max_element(nums.begin(),nums.end()) - *min_element(nums.begin(),nums.end())) * k; 
    }
};