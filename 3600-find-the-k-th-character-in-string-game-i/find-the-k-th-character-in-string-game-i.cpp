class Solution {
public:
    char kthCharacter(int k) {
        string in = "a";
        while(in.size() < k)
        {
            string en = "";
            for(auto it : in)
            {
                it++;
                en += it;
            }
            in += en;
        }
        return in[k-1];
    }
};