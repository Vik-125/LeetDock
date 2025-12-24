class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = 0;  
        for(auto it : apple)
        {
            totalApple += it;
        }

        sort(capacity.begin(),capacity.end(),greater<int>());
        int cnt = 0;
        for(auto it : capacity)
        {
            totalApple -= it;
            cnt++;
            if(totalApple <= 0) return cnt;
        }
        return cnt;
    }
};