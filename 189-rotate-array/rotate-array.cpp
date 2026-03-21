class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k%n;
        // Brute Force
        // vector<int> temp;
        // for(int i=n-k;i<n;i++){
        //     temp.push_back(nums[i]);
        // }

        // for (int i = n - k - 1; i >= 0; i--) {
        //     nums[i + k] = nums[i];
        // }

        // int j = 0;
        // for(int i=0;i<k;i++){
        //     nums[i] = temp[j];
        //     j++;
        // }
        // return;


        // Optimal Approach

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin() + k,nums.end());
        return;
    }
};