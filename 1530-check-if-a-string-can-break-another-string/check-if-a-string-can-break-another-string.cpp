class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int n = s1.size();

        bool flag1 = 1;
        bool flag2 = 1;
        for(int i=0;i<n;i++){
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';

            if(a > b) flag1 = 0;
            if(a < b) flag2 = 0;
        }

        return flag1 || flag2;
    }
};