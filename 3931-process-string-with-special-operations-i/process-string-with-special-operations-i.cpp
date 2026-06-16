class Solution {
public:
    string processStr(string s) {
        string result = "";

        for(auto it : s){
            if(it == '#'){
                result += result;
            }
            else if(it == '%') reverse(result.begin(),result.end());
            else if(it == '*'){
                if(result.size() > 0){
                    result.pop_back();
                }
                continue;
            }
            else result += it;
        }
        return result;
    }
};