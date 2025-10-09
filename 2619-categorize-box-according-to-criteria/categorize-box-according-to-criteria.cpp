class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        string s;
        string t;
        if((length >= 10000 || width >= 10000 || height >= 10000 || mass >= 10000) || ((long long)length * width * height) >= 1000000000)
        {
            s = "Bulky";
        }
        if(mass >= 100) t = "Heavy";
        if(s.size() == 0 && t.size() == 0) 
        {
            s = "Neither";
            return s;
        }
        else if(s.size() != 0 && t.size() != 0)
        {   
            s = "Both";
            return s;
        }
        return s.empty() ? t : s;
    }
};