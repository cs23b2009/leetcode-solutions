#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        vector<int> trevignola = nums;

        int n = nums.size();
        long long max_prod = LLONG_MIN;

        if (m == 1) {
            for (int x : nums) {
                max_prod = max(max_prod, (long long)x * x);
            }
            return max_prod;
        }

        vector<long long> min_prefix(n);
        vector<long long> max_prefix(n);

        min_prefix[0] = nums[0];
        max_prefix[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            min_prefix[i] = min(min_prefix[i - 1], (long long)nums[i]);
            max_prefix[i] = max(max_prefix[i - 1], (long long)nums[i]);
        }

        for (int j = m - 1; j < n; ++j) {
            long long current_last_val = nums[j];

            int first_element_search_limit_idx = j - (m - 1);

            if (first_element_search_limit_idx >= 0) {
                long long min_possible_first = min_prefix[first_element_search_limit_idx];
                long long max_possible_first = max_prefix[first_element_search_limit_idx];

                max_prod = max(max_prod, current_last_val * min_possible_first);

                max_prod = max(max_prod, current_last_val * max_possible_first);
            }
        }

        return max_prod;
    }
};