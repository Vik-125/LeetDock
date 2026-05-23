class Solution {
public:
    bool checkString(string s) {
        int curr = 0;
        int last = 0;
        for(auto it : s){
            curr = it - '0';
            if(curr < last) return false;
            else last = curr;
        }
        return true;
    }
};