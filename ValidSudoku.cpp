class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int len, i, j, s, t;
        len = board.size();
        unordered_map<char, bool> umap;
        /* rules 1 */
        for (i = 0; i < len; i++) {
            umap.clear();
            for (j = 0; j < len; j++) {
                if (board[i][j] == '.') continue;
                else {
                    if (umap.count(board[i][j]) == 0) umap[board[i][j]] = true;
                    else return false;
                }
            }
        }
        /* rules 2 */
        for (i = 0; i < len; i++) {
            umap.clear();
            for (j = 0; j < len; j++) {
                if (board[j][i] == '.') continue;
                else {
                    if (umap.count(board[j][i]) == 0) umap[board[j][i]] = true;
                    else return false;
                }
            }
        }
        /* rules 3 */
        for (i = 0; i <= len-3; i+=3) {
            for (j = 0; j <= len-3; j+=3) {
                umap.clear();
                for (s = i; s < i+3; s++) {
                    for (t = j; t < j+3; t++) {
                        if (board[s][t] == '.') continue;
                        else {
                            if (umap.count(board[s][t]) == 0) umap[board[s][t]] = true;
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
