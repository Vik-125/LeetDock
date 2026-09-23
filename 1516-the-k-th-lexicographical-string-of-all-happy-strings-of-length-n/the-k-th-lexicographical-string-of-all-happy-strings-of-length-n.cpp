class Solution {
public:
    bool find(int n, int k, int &i, string &result, string &s, char prev){
        if(s.size() == n){
            i++;
            if(i == k){
                result = s;
                return true;
            }
            else return false;
        }
        for(auto it : {'a', 'b', 'c'}){
            if(prev != it){
                s.push_back(it);
                if(find(n, k, i, result, s, it)){
                    return true;
                }
                s.pop_back();
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        string result = "";

        int i = 0;
        string s = "";
        find(n, k, i, result, s, ' ');

        return result;
    }
};