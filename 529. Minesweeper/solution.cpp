class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // cout << "clickx: " << click[0] << " clicky: " << click[1] << endl;
        int width = board[0].size();
        int height = board.size();
        
        if (click[0] < 0 || click[0] >= height || click[1] < 0 || click[1] >= width || board[click[0]][click[1]] == 'B') {
            return board;
        }
        
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        if (board[click[0]][click[1]] == 'E') {
            int leftCount = left(board, click) == 'M' ? 1 : 0;
            int topCount = top(board, click) == 'M' ? 1 : 0;
            int rightCount = right(board, click) == 'M' ? 1 : 0;
            int bottomCount = bottom(board, click) == 'M' ? 1 : 0;
            int bottomLeftCount = bottomLeft(board, click) == 'M' ? 1 : 0;
            int bottomRightCount = bottomRight(board, click) == 'M' ? 1 : 0;
            int topLeftCount = topLeft(board, click) == 'M' ? 1 : 0;
            int topRightCount = topRight(board, click) == 'M' ? 1 : 0;
            
            int totalCount = leftCount + topCount + rightCount + bottomCount + bottomLeftCount + bottomRightCount + topLeftCount + topRightCount;
            if (totalCount == 0) {
                board[click[0]][click[1]] = 'B';
                if (left(board, click) == 'E') {
                vector<int> newClick{ click[0], click[1] - 1 };
                updateBoard(board, newClick);
            }
            
            if (top(board, click) == 'E') {
                vector<int> newClick{ click[0] - 1, click[1] };
                updateBoard(board, newClick);
            }
            
            if (right(board, click) == 'E') {
                vector<int> newClick{ click[0], click[1] + 1 };
                updateBoard(board, newClick);
            }
            
            if (bottom(board, click) == 'E') {
                vector<int> newClick{ click[0] + 1, click[1] };
                updateBoard(board, newClick);
            }
            
            if (topLeft(board, click) == 'E') {
                vector<int> newClick{ click[0] - 1, click[1] - 1 };
                updateBoard(board, newClick);
            }
            
            if (topRight(board, click) == 'E') {
                vector<int> newClick{ click[0] - 1, click[1] + 1 };
                updateBoard(board, newClick);
            }
            
            if (bottomLeft(board, click) == 'E') {
                vector<int> newClick{ click[0] + 1, click[1] - 1 };
                updateBoard(board, newClick);
            }
            
            if (bottomRight(board, click) == 'E') {
                vector<int> newClick{ click[0] + 1, click[1] + 1 };
                updateBoard(board, newClick);
            }
            } else {
                board[click[0]][click[1]] = '0' + totalCount;
            }
        }
        
        return board;
    }
    
    char left(vector<vector<char>>& board, vector<int>& click) {
        // Left
        if (click[1] - 1 >= 0) {
            return board[click[0]][click[1] - 1];
        } else {
            return 'E';
        }
    }
    
    char right(vector<vector<char>>& board, vector<int>& click) {
        int width = board[0].size();
        // Right
        if (click[1] + 1 < width) {
            return board[click[0]][click[1] + 1];
        } else {
            return 'B';
        }
    }
    
    char top(vector<vector<char>>& board, vector<int>& click) {
        // Top
        if (click[0] - 1 >= 0) {
            return board[click[0] - 1][click[1]];
        } else {
            return 'B';
        }
    }
    
    char bottom(vector<vector<char>>& board, vector<int>& click) {
        int height = board.size();
         // Bottom
        if (click[0] + 1 < height) {
            return board[click[0] + 1][click[1]];
        } else {
            return 'E';
        }
    }
    
     char topLeft(vector<vector<char>>& board, vector<int>& click) {
        // Top left
        if (click[0] - 1 >= 0 && click[1] - 1 >= 0) {
            return board[click[0] - 1][click[1] - 1];
        } else {
            return 'E';
        }
    }
    
     char topRight(vector<vector<char>>& board, vector<int>& click) {
         int width = board[0].size();
        // Top right 
        if (click[0] - 1 >= 0 && click[1] + 1 < width) {
            return board[click[0] - 1][click[1] + 1];
        } else {
            return 'E';
        }
    }
    
     char bottomLeft(vector<vector<char>>& board, vector<int>& click) {
        int height = board.size();
        // Bottom left
        if (click[0] + 1 < height && click[1] - 1 >= 0) {
            return board[click[0] + 1][click[1] - 1];
        } else {
            return 'E';
        }
    }
    
    char bottomRight(vector<vector<char>>& board, vector<int>& click) {
        int width = board[0].size();
        int height = board.size();
       // Bottom right
        if (click[0] + 1 < height && click[1] + 1 < width) {
            return board[click[0] + 1][click[1] + 1];
        } else {
            return 'E';
        }
    }
};
