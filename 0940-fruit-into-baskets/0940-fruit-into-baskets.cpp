class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int l = 0, maxlen = 0;

        for (int r = 0; r < fruits.size(); ++r) {
            basket[fruits[r]]++;

            // If more than 2 types of fruits, shrink the window from the left
            while (basket.size() > 2) {
                basket[fruits[l]]--;
                if (basket[fruits[l]] == 0) {
                    basket.erase(fruits[l]);
                }
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};