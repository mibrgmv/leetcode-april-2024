class Solution {
public:
    int N, M;

    bool dfs(vector<vector<char>>& board, int i, int j, int k, string word) {
        if (k == word.size()) {
            return true;
        }
        if (i < 0 || i >= N || j < 0 || j >= M || board[i][j] != word[k]) {
            return false;
        }
        char t = board[i][j];
        board[i][j] = '#';
        if (dfs(board, i+1, j, k+1, word) || dfs(board, i-1, j, k+1, word) ||
            dfs(board, i, j+1, k+1, word) || dfs(board, i, j-1, k+1, word)) {
            return true;
        }
        board[i][j] = t;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        N = board.size();
        M = board[0].size();

        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};