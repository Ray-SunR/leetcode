class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                // vector<vector<bool>> visited(board.size(), vector(board[0].size(), false));
                if (dfs(board, word, i, j, 0)) {
                       return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int pos) {
        // cout << "word: " << word[pos] << " i: " << i << " j: " << j << " pos: " << pos << endl;
        char c = board[i][j];
        board[i][j] = '#';
        if (word[pos] != c) { board[i][j] = c; return false; }
        if (pos == word.size() - 1) { return true; }
        // left
        if (j - 1 >= 0 && board[i][j -1] != '#' && dfs(board, word, i, j - 1, pos + 1)) {
            return true;
        }
        // top
        if (i - 1 >=0 && board[i - 1][j] != '#' && dfs(board, word, i - 1, j, pos + 1)) {
            return true;
        }
        // right
        if (j + 1 < board[0].size() && board[i][j + 1] != '#' && dfs(board, word, i, j + 1, pos + 1)) {
            return true;
        }
        // bottom
        if (i + 1 < board.size() && board[i + 1][j] != '#' && dfs(board, word, i + 1, j, pos + 1)) {
            return true;
        }
        board[i][j] = c; // For a char that is not in stack, this char can be used later. But the same char cannot be reused.
        return false;
    }
    
    // bool dfs2(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int pos) {
    //     // cout << "word: " << word[pos] << " i: " << i << " j: " << j << " pos: " << pos << endl;
    //     visited[i][j] = true;
    //     if (word[pos] != board[i][j]) { visited[i][j] = false; return false; }
    //     if (pos == word.size() - 1) { return true; }
    //     // left
    //     if (j - 1 >= 0 && !visited[i][j -1] && dfs2(board, word, visited, i, j - 1, pos + 1)) {
    //         return true;
    //     }
    //     // top
    //     if (i - 1 >=0 && !visited[i - 1][j] && dfs2(board, word, visited, i - 1, j, pos + 1)) {
    //         return true;
    //     }
    //     // right
    //     if (j + 1 < board[0].size() && !visited[i][j + 1] && dfs2(board, word, visited, i, j + 1, pos + 1)) {
    //         return true;
    //     }
    //     // bottom
    //     if (i + 1 < board.size() && !visited[i + 1][j] && dfs2(board, word, visited, i + 1, j, pos + 1)) {
    //         return true;
    //     }
    //     visited[i][j] = false; // For a char that is not in stack, this char can be used later. But the same char cannot be reused.
    //     return false;
    // }
};
