class Solution {
public:
    vector<int> find(int i, vector<int> nums){
        int n = nums.size();
        int mini = INT_MAX;
        vector<int> res;

        for(int i=0;i<n-1;i++){
            if(mini > nums[i] + nums[i+1]){
                res.clear();
                res.push_back(i);
                res.push_back(i+1);

                mini = nums[i] + nums[i+1];
            }
        }
        return res;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;
        bool flag = true;
        vector<int> temp;

        while(flag){
            flag = false;
            vector<int> ind;
            for(int i=0;i<nums.size()-1;i++){
                ind.clear();
                if(nums[i] > nums[i+1]){
                    ind = find(i+1, nums);
                    op++;
                    flag = true;
                    break;
                }
            }
            if(flag == true){   
                int l = ind[0];
                for(int i=0;i<nums.size();i++){
                    if(i == l){
                        temp.push_back(nums[i] + nums[i+1]);
                        i++;
                    }
                    else temp.push_back(nums[i]);
                }
                nums = temp;
                temp.clear();
            }
        }
        return op;
    }
};