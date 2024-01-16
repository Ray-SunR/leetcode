class Solution:
    def dfs(self, board, x, y, component):
        board[x][y] = component
        # expand horizontally
        if y + 1 < len(board[x]) and board[x][y + 1] == 'X':
            self.dfs(board, x, y + 1, component)

        # expand vertically
        if x + 1 < len(board) and board[x + 1][y] == 'X':
            self.dfs(board, x + 1, y, component)
        
    def countBattleships(self, board: List[List[str]]) -> int:
        component = 0 
        for x in range(len(board)):
            for y in range(len(board[x])):
                if board[x][y] == 'X':
                    self.dfs(board, x, y, str(component))
                    component += 1
        return component