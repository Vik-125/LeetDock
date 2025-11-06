class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> seen;
        double avg = 0;

        int l = 0;
        int r = nums.size() - 1;
        sort(nums.begin(),nums.end());

        while(l < r)
        {
            double m = nums[l];
            double n = nums[r];

            avg = (m+n)/2;
            seen.insert(avg);
            l++;
            r--;
        }
        return seen.size();
    }
};