#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numIndex;

        // Store original indices with their values
        for (int i = 0; i < n; ++i) {
            numIndex.emplace_back(nums[i], i);
        }

        // Sort by value (ascending)
        sort(numIndex.begin(), numIndex.end());

        // Apply two-pointer technique
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numIndex[left].first + numIndex[right].first;
            if (sum == target) {
                return {numIndex[left].second, numIndex[right].second};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        return {};  // Return empty if no valid pair found
    }
};