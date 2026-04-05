class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        long long ans = r;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long hours = 0;
            for (int p : piles)
                hours += (p + mid - 1) / mid;

            if (hours <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};