class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<char>> row, col, sq;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char val = board[i][j];
                int bx = i / 3 * 3 + j / 3;

                if (val == '.') continue;
                if (row[i].contains(val) || col[j].contains(val) || sq[bx].contains(val))
                    return false;

                row[i].insert(val);
                col[j].insert(val);
                sq[bx].insert(val);
            }
        }
        return true;
    }
};
