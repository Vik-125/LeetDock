class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> hash;
        k = n - k + 1;

        for(auto it : nums){
            hash[it]++;
        }

        for(auto it : hash){
            k -= it.second;
            if(k <= 0) return it.first;
        }
        return 0;
    }
};