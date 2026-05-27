class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int> hash;
        int cnt = 0;
        for(int i=0;i<word.size();i++){
            int k = (int)word[i];
            if(k >= 65 && k < 91 && hash.count(k)){
                continue;
            }
            hash[k] = i;
        }
        for(auto it : hash){
            int a = it.first;
            int b = it.second;
            if(hash.count(a-32) && hash[a-32] > b) cnt++;
        }
        return cnt;
    }
};