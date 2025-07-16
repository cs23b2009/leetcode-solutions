class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int>dp(n, 1);
        vector<int>count(n, 1);

        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];  // reset count if we encounter new maximum value
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j]; // accumulate ways - adding the count of prev ways to this elements'
                    }
                }

            }
            maxi = max(maxi, dp[i]);
        }

        //if(maxi == 1) return n;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi) ans+=(count[i]);
        }
        return ans;

    }
};