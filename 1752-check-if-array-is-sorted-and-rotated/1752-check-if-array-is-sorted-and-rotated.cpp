class Solution {
public:
    bool check(vector<int>& numbers) {
        int length = numbers.size();
        if (length <= 2) return true;

        int dropCount = 0;

        for (int index = 1; index < length; index++) {
            if (numbers[index] < numbers[index - 1]) {
                dropCount++;
                if (dropCount > 1) return false;
            }
        }

        if (dropCount == 0) return true;

        return numbers[length - 1] <= numbers[0];
    }
};