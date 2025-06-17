class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Initialize bitmasks for rows, columns, and boxes
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int mask = 1 << (board[r][c] - '1');
                    rows[r] |= mask;
                    cols[c] |= mask;
                    boxes[boxIndex(r, c)] |= mask;
                } else {
                    emptyCells.emplace_back(r, c);
                }
            }
        }
        backtrack(board, 0);
    }

private:
    int rows[9] = {}, cols[9] = {}, boxes[9] = {};
    vector<pair<int, int>> emptyCells;

    inline int boxIndex(int r, int c) {
        return (r / 3) * 3 + (c / 3);
    }

    bool backtrack(vector<vector<char>>& board, int idx) {
        if (idx == emptyCells.size()) return true;

        auto [r, c] = emptyCells[idx];
        int b = boxIndex(r, c);

        for (int d = 0; d < 9; ++d) {
            int mask = 1 << d;
            if (!(rows[r] & mask) && !(cols[c] & mask) && !(boxes[b] & mask)) {
                board[r][c] = d + '1';
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[b] |= mask;

                if (backtrack(board, idx + 1)) return true;

                board[r][c] = '.';
                rows[r] ^= mask;
                cols[c] ^= mask;
                boxes[b] ^= mask;
            }
        }
        return false;
    }
};