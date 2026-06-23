class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> firstApp;
        unordered_map<int,int> lastApp;

        int maxDegree = 0;
        int n = nums.size();
        int maxi = n;

        for(int i=0;i<n;i++){
            int k = nums[i];
            if(freq[k] == 0){
                firstApp[k] = i;
                lastApp[k] = i;
                freq[k]++;
            }
            else{
                freq[k]++;
                lastApp[k] = i;
            }     
            maxDegree = max(maxDegree, freq[k]);
        }
        for(int i=0;i<n;i++){
            int k = nums[i];
            if(maxDegree == freq[k]){
                maxi = min(lastApp[k] - firstApp[k] + 1, maxi);
            }
        }
        return maxi;

    }
};