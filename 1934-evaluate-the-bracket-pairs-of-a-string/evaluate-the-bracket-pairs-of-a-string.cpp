class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> hash;
        for(const auto &it : knowledge){
            string a = it[0];
            string b = it[1];
            hash[a] = b;
        }
        
        int n = s.size();
        string result = "";
        int i = 0;

        while(i < n){
            if(s[i] == '('){
                i++;
                string temp = "";
                while(s[i] != ')'){
                    temp += s[i];
                    i++;
                }
                i++;
                if(hash.find(temp) != hash.end()){
                    result += hash[temp];
                }
                else result += '?';
            }
            else{
                result += s[i];
                i++;
            }
        }
        return result;
    }
};