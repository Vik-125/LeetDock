class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<int,int> hash;

        for(auto it : word){
            hash[(int)it]++;
        }
        int cnt = 0;
        for(auto it : hash){
            int a = it.first;

            if(hash.count(a+32) > 0) cnt++;
        }
        return cnt;
    }
};