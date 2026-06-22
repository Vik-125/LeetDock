class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> hash;

        for(auto &it : text) {
            if(it == 'b' || it == 'a' || it == 'l' || it == 'o' || it == 'n') hash[it]++;
            else continue;
        }
        if(hash.size() != 5) return 0;

        int mini = INT_MAX;
        for(auto &it : hash){
            if(it.first == 'o' || it.first == 'l'){
                mini = min(mini,it.second/2);
                continue;
            }
            mini = min(mini,it.second);
        }
        return mini;
    }
};