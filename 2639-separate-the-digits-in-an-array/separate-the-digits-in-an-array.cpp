class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digs;
        int dig = 0;
        for(auto it : nums){
            vector<int> temp;
            while(it > 0){
                dig = it%10;
                temp.push_back(dig);
                it /= 10;
            }
            reverse(temp.begin(),temp.end());
            digs.insert(digs.end(),temp.begin(),temp.end());
            temp.clear();
        }
        return digs;
    }
};