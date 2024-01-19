class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        component_id = 1
        xs = {}
        for x in range(len(board)):
            for y in range(len(board[x])):
                if board[x][y] == "O":
                    coords = []
                    self.dfs(board, x, y, str(component_id), coords)
                    xs[str(component_id)] = coords
                    component_id += 1

        for component_id in xs:
            if not self.can_reach_border(xs[component_id], len(board), len(board[0])):
                for x, y in xs[component_id]:
                    board[x][y] = "X"
            else:
                for x, y in xs[component_id]:
                    board[x][y] = "O"

    def dfs(self, board, x, y, component_id, coords):
        board[x][y] = component_id
        coords.append((x, y))
        # left
        if y - 1 >= 0 and board[x][y - 1] == "O":
            self.dfs(board, x, y - 1, component_id, coords)
        # top
        if x - 1 >= 0 and board[x - 1][y] == "O":
            self.dfs(board, x - 1, y, component_id, coords)
        # right
        if y + 1 < len(board[x]) and board[x][y + 1] == "O":
            self.dfs(board, x, y + 1, component_id, coords)
        # bottom
        if x + 1 < len(board) and board[x + 1][y] == "O":
            self.dfs(board, x + 1, y, component_id, coords)

    def can_reach_border(self, coords, m, n):
        for x, y in coords:
            if x == 0 or y == 0 or x == m - 1 or y == n - 1:
                return True
