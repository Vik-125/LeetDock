class Solution {
public:
    bool isFascinating(int n) {
        string s;
        s = to_string(n);
        s += to_string(n*2);
        s += to_string(n*3);

        if(s.length() != 9) return false;
        unordered_map<char,int> hash;
        for(auto it : s)
        {
            hash[it]++;
        }

        for(auto& [key,value] : hash)
        {
            if(value == 0 || value > 1 || key == '0') return false;
        }
        return true;
    }
};