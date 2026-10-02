class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indexes;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] == key) indexes.push_back(i);
        }

        set<int> result;
        for(int m=0;m<indexes.size();m++){
            int j = indexes[m];
            int i=0;
            while(i < n){
                if(abs(j - i) <= k) {
                    result.insert(i);
                }
                i++;
            }
        }
        vector<int> in;
        for(auto it : result){
            in.push_back(it);
        }
        return in;
    }
};