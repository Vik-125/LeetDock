class Solution {
public:
    string reverseParentheses(string s) {
        string result;

        stack<char> st;
        for(auto it : s){
            st.push(it);
            if(st.top() == ')'){
                st.pop();
                string temp = "";
                while(st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(auto it : temp) st.push(it);
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