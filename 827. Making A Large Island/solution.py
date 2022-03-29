class Solution:
    def dfs(self, grid, x, y, component_id):
        # means this island has been spoken for
        if grid[x][y] != 1:
            return
        grid[x][y] = component_id
        if component_id not in self.size:
            self.size[component_id] = 0
        self.size[component_id] += 1
        self.largest_size = max(self.largest_size, self.size[component_id])
        
        # left
        if y - 1 >= 0:
            self.dfs(grid, x, y - 1, component_id)
        # top
        if x - 1 >= 0:
            self.dfs(grid, x - 1, y, component_id)
        # right
        if y + 1 < len(grid[x]):
            self.dfs(grid, x, y + 1, component_id)
        # bottom
        if x + 1 < len(grid):
            self.dfs(grid, x + 1, y, component_id)
        
    def largestIsland(self, grid: List[List[int]]) -> int:
        # tag each island with a component id and keep track their size. 
        # scan through each coords, if it's 0, try flip it to 1 and see what is the largest island it can form
        # keep track of the largest one
        self.size = {}
        self.largest_size = -math.inf
        component_id = -1
        for x in range(len(grid)):
            for y in range(len(grid[x])):
                if grid[x][y] == 1:
                    self.dfs(grid, x, y, component_id)
                    component_id -= 1
        
        ret = -math.inf
        for x in range(len(grid)):
            for y in range(len(grid[x])):
                if grid[x][y] == 0:
                    components = set()
                    # left
                    if y - 1 >= 0 and grid[x][y - 1] != 0:
                        components.add(grid[x][y - 1])
                    # top
                    if x - 1 >= 0 and grid[x - 1][y] != 0:
                        components.add(grid[x - 1][y])
                    # right
                    if y + 1 < len(grid[x]) and grid[x][y + 1] != 0:
                        components.add(grid[x][y + 1])
                    # bottom
                    if x + 1 < len(grid) and grid[x + 1][y] != 0:
                        components.add(grid[x + 1][y])
                    
                    total_size = 0
                    for com in components:
                        total_size += self.size[com]
                    ret = max(ret, total_size + 1)
                        
        # print(grid)
        # print(self.size)
        return max(ret, self.largest_size)
