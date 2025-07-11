#include <algorithm>
#include <vector>
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n  = triangle.size();
        int m = triangle[n-1].size();
        vector<int> prev(m,0);
        prev[0] = triangle[0][0];
        for(int i=1;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<=i;j++){
                int up = INT_MAX;
                if(i!=j) up = prev[j];
                int upleft = INT_MAX;
                if(j>0) upleft = prev[j-1];
                curr[j] = min(up,upleft) + triangle[i][j];
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for(int i=0;i<m;i++){
            mini = min(mini,prev[i]);
        }
        return mini;
    }

};