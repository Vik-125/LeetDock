class Solution {
public:
    int sum(int k){
        int sum = 0;
        while(k > 0){
            sum += k%10;
            k /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <= 9) continue;
            else nums[i] = (sum(nums[i]));
        }
        return *min_element(nums.begin(),nums.end());
    }
};