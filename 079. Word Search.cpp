// 声明visited 数组一定要在最外面！！！
class Solution {
public:
    bool DFS (vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int pos, int i, int j) {
        if (pos == word.size())
            return true;
        else if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        else if (word[pos] != board[i][j] || visited[i][j] == true)
            return false;
        visited[i][j] = true;
        bool exist = DFS(board, visited, word, pos + 1, i + 1, j)
                      || DFS(board, visited, word, pos + 1, i, j + 1)
                      || DFS(board, visited, word, pos + 1, i - 1, j)
                      || DFS(board, visited, word, pos + 1, i, j - 1);
        visited[i][j] = false;
        return exist;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0)
            return false;
        vector<vector<bool>> visited (board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (DFS (board, visited, word, 0, i, j) == true)
                    return true;
            }
        }
        return false;
    }
};
