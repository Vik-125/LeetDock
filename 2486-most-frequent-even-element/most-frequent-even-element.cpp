class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> hash;
        
        for(auto it : nums){
            if(it % 2 == 0){
                hash[it]++;
            }
        }

        int maxFreq = 0;
        int minEle = -1;
        for(const auto &it : hash){
            int ele = it.first;
            int freq = it.second;

            if(freq > maxFreq){
                    minEle = ele;
                    maxFreq = freq;
                }
                else if(freq == maxFreq){
                    if(minEle > ele){
                        minEle = ele;
                    }
                }
        }
        return minEle;
    }
};