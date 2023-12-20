ass Solution:
    def dfs(self, grid, x, y, component_id, components):
        components[x][y] = component_id
        if component_id == 0:
            self.candidates.append((x, y, 0))
        # left
        if y - 1 >= 0 and grid[x][y - 1] == 1 and components[x][y - 1] == -1:
            self.dfs(grid, x, y - 1, component_id, components)
        # top
        if x - 1 >= 0 and grid[x - 1][y] == 1 and components[x - 1][y] == -1:
            self.dfs(grid, x - 1, y, component_id, components)
        # right
        if y + 1 < len(grid[x]) and grid[x][y + 1] == 1 and components[x][y + 1] == -1:
            self.dfs(grid, x, y + 1, component_id, components)
        # bottom
        if x + 1 < len(grid) and grid[x + 1][y] == 1 and components[x + 1][y] == -1:
            self.dfs(grid, x + 1, y, component_id, components)
        
    def bfs(self, components):
        visited = [[False] * len(components[0]) for i in range(0, len(components))]
        ret = 99999999
        for candidate in self.candidates:
            visited[candidate[0]][candidate[1]] = True
        while self.candidates:
            xx, yy, dist = self.candidates.pop(0)
            # print("xx: {}, yy: {}, dist: {}".format(xx, yy, dist))
            if components[xx][yy] == 1:
                # found it 
                ret = min(ret, dist)
                continue
            # left is water
            if yy - 1 >= 0 and components[xx][yy - 1] != 0 and not visited[xx][yy - 1]:
                visited[xx][yy - 1] = True
                self.candidates.append((xx, yy - 1, dist + 1))
            
            # top is water
            if xx - 1 >= 0 and components[xx - 1][yy] != 0 and not visited[xx - 1][yy]:
                visited[xx - 1][yy] = True
                self.candidates.append((xx - 1, yy, dist + 1))
            
            # right
            if yy + 1 < len(components[xx]) and components[xx][yy + 1] != 0 and not visited[xx][yy + 1]:
                visited[xx][yy + 1] = True
                self.candidates.append((xx, yy + 1, dist + 1))
                
            # bottom
            if xx + 1 < len(components) and components[xx + 1][yy] != 0 and not visited[xx + 1][yy]:
                visited[xx + 1][yy] = True
                self.candidates.append((xx + 1, yy, dist + 1))
        return ret
                
            
    def shortestBridge(self, grid: List[List[int]]) -> int:
        component_id = 0
        self.candidates = []
        components = [[-1] * len(grid[0]) for i in range(0, len(grid))]

        for x in range(0, len(grid)):
            for y in range(0, len(grid[x])):
                if grid[x][y] == 1 and components[x][y] == -1:
                    self.dfs(grid, x, y, component_id, components)
                    component_id += 1
        # print(components)
        # print(self.candidates)
        return self.bfs(components) - 1
