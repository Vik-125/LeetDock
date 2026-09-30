class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int n = s1.size();

        bool flag1 = 1;
        bool flag2 = 1;
        for(int i=0;i<n;i++){
            if(s1[i] - 'a' > s2[i] - 'a') flag1 = 0;
            if(s1[i] - 'a' < s2[i] - 'a') flag2 = 0;
        }

        return flag1 || flag2;
    }
};