class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maxNum = num, minNum = num;

        for (char d : s) {
            if (d != '9') {
                string temp = s;
                for (char& c : temp)
                    if (c == d) c = '9';
                maxNum = max(maxNum, stoi(temp));
                break;
            }
        }

        for (char d : s) {
            if (d != '0') {
                string temp = s;
                for (char& c : temp)
                    if (c == d) c = '0';
                minNum = min(minNum, stoi(temp));
                break; 
            }
        }

        return maxNum - minNum;
    }
};