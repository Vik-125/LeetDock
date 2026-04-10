class Solution {
public:
    bool check(vector<int> &nums,int threshold,int mid){
        int sum = 0;

        for(int i=0;i<nums.size();i++){
            sum += ceil((double)nums[i]/mid);
        }
        return sum > threshold ? 1 : 0;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(nums,threshold,mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};