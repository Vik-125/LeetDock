class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> hash;

        int l = 0;
        int r = nums.size();

        while(l < r){
            int p = 0;
            unordered_set<int> seen;
            while(p < k && k+l <= r){
                if(seen.find(nums[p+l]) == seen.end()){
                    seen.insert(nums[p+l]);
                    hash[nums[p+l]]++;
                }
                p++;
            }
            l++;
        }
        int maxi = -1;
        for(auto it : hash){
            int m = it.first;
            int n = it.second;

            cout << m << n << endl;;

            if(n == 1){
                maxi = max(maxi,m);
            }
        }
        return maxi;
    }
};