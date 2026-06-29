class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        string s2 = "";
        for(int i=n-1;i>=0;i--){
            s2 += s1[i];
        }
        vector<int> prev(n+1,0);
        for(int i=1;i<=n;i++){
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};