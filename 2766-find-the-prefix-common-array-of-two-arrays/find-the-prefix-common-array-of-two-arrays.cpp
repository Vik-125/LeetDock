class Solution {
public:
    int check(vector<int> freqA,vector<int> freqB,int n)
    {
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(freqA[i] >= 1 && freqB[i] >= 1) cnt++;
        }
        return cnt;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n = A.size();

        vector<int> freqA(n+1,0);
        vector<int> freqB(n+1,0);

        for(int i=0;i<A.size();i++)
        {
            freqA[A[i]]++;
            freqB[B[i]]++;
            ans.push_back(check(freqA,freqB,n));
        }
        return ans;
    }
};