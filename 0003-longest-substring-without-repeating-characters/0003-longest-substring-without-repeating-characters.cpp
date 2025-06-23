class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];

            // If the character is already seen and is inside the current window
            if (lastSeen.find(currentChar) != lastSeen.end() && lastSeen[currentChar] >= start) {
                // Move the start just after the last seen position
                start = lastSeen[currentChar] + 1;
            }

            // Update the last seen index of the character
            lastSeen[currentChar] = end;

            // Update maxLength if the current window is larger
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};