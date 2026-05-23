class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0 || s.size()==1){
            return false;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    return false;
                }
                else if(st.top()=='('){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(st.size()==0){
                    return false;
                }
                else if(st.top()=='{'){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(st.size()==0){
                    return false;
                }
                else if(st.top()=='['){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        if(st.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};