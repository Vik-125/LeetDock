class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int b=0;
        for(int i=1; i<n; i++)
        {
            if(nums[i] != nums[b]){
            nums[b+1] = nums[i];
            b++;
           }
        }
        return b+1;
    }
};