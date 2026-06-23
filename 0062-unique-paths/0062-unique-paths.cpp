class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> present(n,0);
        vector<int> past(n,0);
        present[0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(i>0){
                    present[j] = past[j];
                }
                if(j>0){
                    present[j] +=  present[j-1];
                }
            }
            past = present;
        }
        return present[n-1];
    }
};