class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> hash;
        set<int> doubleHash;

        for(auto it : arr){
            hash[it]++;
        }
        for(auto it : hash){
            int a = it.second;
            if(!doubleHash.insert(a).second) return false;
            
        }
        return true;
    }
};