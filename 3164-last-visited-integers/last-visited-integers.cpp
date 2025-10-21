class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> post,ans;
        int k = 0;

        for(auto it : nums)
        {
            if(it > 0)
            {
                post.insert(post.begin(),it);
                k = 0;
            }
            else if(it == -1)
            {
                k++;
                if(k <= post.size())
                {
                    ans.push_back(post[k - 1]);
                }
                else if(k > post.size())
                {
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};