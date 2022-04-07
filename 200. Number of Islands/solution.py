class Solution:
    def dfs(self, grid, i, j):
        grid[i][j] = "x"
        # left
        if j - 1 >= 0 and grid[i][j - 1] == "1":
            # grid[i][j - 1] = "x"
            self.dfs(grid, i, j - 1)
        # top
        if i - 1 >= 0 and grid[i - 1][j] == "1":
            # grid[i][j - 1] = "x"
            self.dfs(grid, i - 1, j)
        # right
        if j + 1 < len(grid[i]) and grid[i][j + 1] == "1":
            # grid[i][j + 1] = "x"
            self.dfs(grid, i, j + 1)
        # bottom
        if i + 1 < len(grid) and grid[i + 1][j] == "1":
            # grid[i + 1][j] = "x"
            self.dfs(grid, i + 1, j)
            
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == "1":
                    count += 1
                    self.dfs(grid, i, j)
        # print(grid)
        return count
