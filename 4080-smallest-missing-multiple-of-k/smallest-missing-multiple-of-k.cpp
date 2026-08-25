class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int multiple = 1;
        sort(nums.begin(),nums.end());

        for(auto it : nums){
            if(it == k*multiple){
                multiple++;
            }
        }
        return multiple*k;
    }
};