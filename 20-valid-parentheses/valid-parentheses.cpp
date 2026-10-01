class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(const auto &it : s){
            if(it == '(' || it == '{' || it == '[') st.push(it);
            else if(st.empty()) return false;
            else if((it == ')' && st.top() == '(') || (it == ']' && st.top() == '[') || (it == '}' && st.top() == '{')) st.pop();
            else return false;
        }
        return st.empty();
    }
};