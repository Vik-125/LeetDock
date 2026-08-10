class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size()-1;
        int i = 0;
        int sum = 0;
        while(i <= n){
            sum = numbers[i] + numbers[n];
            if(sum == target) return {i+1,n+1};
            else if(sum > target) n--;
            else i++;
        }
        return {};
    }
};