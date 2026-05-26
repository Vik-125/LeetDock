class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int> hash;

        for(auto it : word){
            hash[(int)it]++;
        }
        int i = 0;
        int cnt = 0;
        for(auto it : hash){
            i++;
            int a = it.first;
            cout << a << endl;

            if(hash.count(a+32) > 0) cnt++;
        }
        cout << i;
        return cnt;
    }
};