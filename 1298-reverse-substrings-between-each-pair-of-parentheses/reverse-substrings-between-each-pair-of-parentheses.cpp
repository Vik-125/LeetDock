class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        result.reserve(s.size());

        stack<char> st;
        for(const auto &it : s){
            st.push(it);
            if(st.top() == ')'){
                st.pop();
                string temp = "";
                while(st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(const auto &it : temp) st.push(it);
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};