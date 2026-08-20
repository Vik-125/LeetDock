class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i = 0;
        int j = 0;
        int k = 2;

        for(int k=2;k<nums.size();k++){
            if(arr1[i] > arr2[j]){
                arr1.push_back(nums[k]);
                i++;
            }
            else{
                arr2.push_back(nums[k]);
                j++;
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};