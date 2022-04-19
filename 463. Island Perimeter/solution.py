class Solution:
    def dfs(self, grid, x, y):
        grid[x][y] = -1
        
        # left
        if y - 1 >= 0 and grid[x][y - 1] == 1:
            self.dfs(grid, x, y - 1)
        if y == 0 or (y - 1 >= 0 and grid[x][y - 1] == 0):
            # print("x: " + str(x) + " y: " + str(y) + " left")
            self.ret += 1
            
        # top
        if x - 1 >= 0 and grid[x - 1][y] == 1:
            self.dfs(grid, x - 1, y)
        if x == 0 or (x - 1 >= 0 and grid[x - 1][y] == 0):
            # print("x: " + str(x) + " y: " + str(y) + " top")
            self.ret += 1
        
        # right
        if y + 1 < len(grid[x]) and grid[x][y + 1] == 1:
            self.dfs(grid, x, y + 1)
        if y == len(grid[x]) - 1 or (y + 1 < len(grid[x]) and grid[x][y +1 ] == 0):
            # print("x: " + str(x) + " y: " + str(y) + " right")
            self.ret += 1
            
        # bottom
        if x + 1 < len(grid) and grid[x + 1][y] == 1:
            self.dfs(grid, x + 1, y)
        if x == len(grid) - 1 or (x + 1 < len(grid) and grid[x + 1][y] == 0):
            # print("x: " + str(x) + " y: " + str(y) + " bottom")
            self.ret += 1
        
        
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        self.ret = 0
        for x in range(len(grid)):
            for y in range(len(grid[x])):
                if grid[x][y] == 1:
                    self.dfs(grid, x, y)
        return self.ret
