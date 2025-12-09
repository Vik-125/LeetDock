class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            int a = i;
            for(int j=1;j<=n;j++)
            {
                int b = j;
                int c2 = (a*a + b*b);
                int c = sqrt(c2);
                if(c <= n && c*c == c2) cnt++;
            }
        }
        return cnt;
    }
};