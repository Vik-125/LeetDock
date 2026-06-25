class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int n = nums.size();
        int result = 0;

        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         unordered_map<int,int> hash;
        //         for(int k=i;k<=j;k++){
        //             hash[nums[k]]++;
        //         }
        //         if(hash[target]*2 > j-i+1) result++;
        //     }
        // }
        for(int i=0;i<n;i++){
            unordered_map<int,int> hash;
            for(int j=i;j<n;j++){
                hash[nums[j]]++;
                if(hash[target]*2 > j-i+1) result++;
            }
        }
        return result;
    }
};