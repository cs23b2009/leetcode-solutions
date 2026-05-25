class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size()) return "0";
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        int ii = 0;
        reverse(ans.begin(),ans.end());
        while(ii<ans.size() && ans[ii]=='0'){
            ii++;
        }
        ans =  ans.substr(ii);
        return ans == "" ? "0" : ans;
    }
};