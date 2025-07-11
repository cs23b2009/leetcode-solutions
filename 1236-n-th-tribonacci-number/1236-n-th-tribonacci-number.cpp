class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        int prev1 = 0;
        int prev2 = 1;
        int prev3 = 1;
        for(int i=2;i<n;i++){
            int prev = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = prev;
        }
        return prev3;
    }
};