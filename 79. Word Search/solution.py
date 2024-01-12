
class Solution:
    def dfs(self, board, s, word, x, y, visited):
        visited.add((x, y))
        # print('x: {}, y: {}, s: {}'.format(x, y, s))
        # print(visited)
        if s == word:
            return True
        # left
        if y - 1 >= 0 and (x, y - 1) not in visited and board[x][y - 1] == word[len(s)]:
            if self.dfs(board, s + word[len(s)], word, x, y - 1, visited):
                return True
            else:
                visited.remove((x, y - 1))
        # top
        if x - 1 >= 0 and (x - 1, y) not in visited and board[x - 1][y] == word[len(s)]:
            if self.dfs(board, s + word[len(s)], word, x - 1, y, visited):
                return True
            else:
                visited.remove((x - 1, y))
        # right
        if y + 1 < len(board[x]) and (x, y + 1) not in visited and board[x][y + 1] == word[len(s)]:
            if self.dfs(board, s + word[len(s)], word, x, y + 1, visited):
                return True
            else:
                visited.remove((x, y + 1))
        # bottom
        if x + 1 < len(board) and (x + 1, y) not in visited and board[x + 1][y] == word[len(s)]:
            if self.dfs(board, s + word[len(s)], word, x + 1, y, visited):
                return True
            else:
                visited.remove((x + 1, y))
    """
    @param board: A list of lists of character
    @param word: A string
    @return: A boolean
    """
    def exist(self, board: List[List[str]], word: str) -> bool:
        candidates = []
        for x in range(len(board)):
            for y in range(len(board[x])):
                if board[x][y] == word[0]:
                    candidates.append((word[0], x, y))
        # print(candidates)
        # write your code here
        for candidate in candidates:
            visited = set()
            if self.dfs(board, candidate[0], word, candidate[1], candidate[2], visited):
                return True
        return False
        '''
        ABCE
        SFES
        ADEE
        '''
        