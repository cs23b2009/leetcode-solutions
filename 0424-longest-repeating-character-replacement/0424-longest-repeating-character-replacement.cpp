class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = 0;
        int l = 0;
        int maxi = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < n; r++) {
            freq[tolower(s[r]) - 'a']++;
            maxi = max(maxi, freq[tolower(s[r]) - 'a']);

            // Check how many characters we need to change
            int length = r - l + 1;
            int changes = length - maxi;

            // If changes exceed k, shrink the window
            if (changes > k) {
                freq[tolower(s[l]) - 'a']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};