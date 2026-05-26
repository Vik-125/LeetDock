class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> hash;
        map<int,int> doubleHash;

        for(auto it : arr){
            hash[it]++;
        }
        for(auto it : hash){
            int a = it.second;
            doubleHash[a]++;
        }
        for(auto it : doubleHash){
            int b = it.second;
            if(b > 1) return false;
        }
        return true;
    }
};