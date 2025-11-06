class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_map<double,int> hash;
        double avg = 0;

        int l = 0;
        int r = nums.size() - 1;
        int cnt = 0;
        sort(nums.begin(),nums.end());

        while(l < r)
        {
            double m = nums[l];
            double n = nums[r];

            avg = (m+n)/2;
            if(hash.count(avg) == 0) 
            {
                hash[avg]++;
                cnt++;
            }
            l++;
            r--;
        }
        return cnt;
    }
};