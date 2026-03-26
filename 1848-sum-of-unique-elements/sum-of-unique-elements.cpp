class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> hash;

        for(auto it : nums){
            hash[it]++;
        }

        int sum = 0;
        for(auto it : hash){
            if(it.second == 1) sum += it.first;
        }

        return sum;
    }
};