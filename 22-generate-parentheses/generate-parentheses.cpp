class Solution {
public:
    void make(int n, vector<string> &result, string temp){
        if(temp.size() == 2*n){
            stack<char> st;
            bool flag = true;
            for(auto it : temp){
                if(st.empty()){
                    st.push(it);
                    continue;
                }
                if(it == ')' && st.top() == '('){
                    st.pop();
                }
                else if(it == ')' && st.top() != '('){
                    flag = false;
                    break;
                }
                else st.push(it);
            }
            if(st.empty())  result.push_back(temp);
            return;
        }
        make(n, result, temp + '(');
        make(n, result, temp + ')');
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";

        make(n, result, temp);
        return result;
    }
};