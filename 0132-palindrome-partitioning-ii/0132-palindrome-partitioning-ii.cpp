class Solution {
public:
    bool palindrome(int i, int j, string&s){
        while(i<j){
            if(s[i]==s[j]){
                i++; j--;
            }
            else return false;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int ans = 1e9;
            for(int j=i; j<n; j++){
                if(palindrome(i, j, s)){
                    int cost = 1+dp[j+1];
                    ans = min(ans, cost);
                }
            }
            dp[i] = ans;
        }
        return dp[0]-1;
    }
};