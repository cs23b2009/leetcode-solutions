class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int original = x, reverse = 0;

        while (x != 0) {
            int digit = x % 10;

            if (reverse > (INT_MAX - digit) / 10)
                return false;

            reverse = reverse * 10 + digit;
            x /= 10;
        }

        return reverse == original;
    }
};