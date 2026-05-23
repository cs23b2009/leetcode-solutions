class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = true;

        for(char ch : s) {

            rows[currentRow] += ch;

            if(currentRow == 0) {
                goingDown = true;
            }
            else if(currentRow == numRows - 1) {
                goingDown = false;
            }


            if(goingDown) {
                currentRow++;
            }
            else {
                currentRow--;
            }
        }

        string ans = "";

        for(string row : rows) {
            ans += row;
        }

        return ans;
    }
};