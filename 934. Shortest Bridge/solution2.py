class Solution:
    def dfs(self, grid, x, y, component_id, candidates):
        grid[x][y] = component_id
        candidates.append((x, y))
        # left
        if y - 1 >= 0 and grid[x][y - 1] == 1:
            self.dfs(grid, x, y - 1, component_id, candidates)
        # top
        if x - 1 >= 0 and grid[x - 1][y] == 1:
            self.dfs(grid, x - 1, y, component_id, candidates)
        # right
        if y + 1 < len(grid[x]) and grid[x][y + 1] == 1:
            self.dfs(grid, x, y + 1, component_id, candidates)
        # bottom
        if x + 1 < len(grid) and grid[x + 1][y] == 1:
            self.dfs(grid, x + 1, y, component_id, candidates)
        
    def shortestBridge(self, grid: List[List[int]]) -> int:
        candidates = []
        # first island has a component_id of 2
        component_id = 2
        for x in range(len(grid)):
            for y in range(len(grid[x])):
                if grid[x][y] == 1: 
                    self.dfs(grid, x, y, component_id, candidates if component_id == 2 else [])
                    component_id += 1
        # print(candidates)
        # print(grid)
        # use BFS using candidates until find component_id of 3
        q = [(0, x, y) for x, y in candidates]

        while q:
            dis, x, y = heapq.heappop(q)
            # print('dis: {}, x: {}, y: {}'.format(dis, x, y))
            if grid[x][y] == 3:
                return dis - 1
            # left
            if y - 1 >= 0 and grid[x][y - 1] != 2 and grid[x][y - 1] != -1:
                if grid[x][y - 1] == 3:
                    return dis
                # mark the bridge as '-1'
                grid[x][y - 1] = -1
                heapq.heappush(q, (dis + 1, x, y - 1))
                
            # top
            if x - 1 >= 0 and grid[x - 1][y] != 2 and grid[x - 1][y] != -1:
                if grid[x - 1][y] == 3:
                    return dis
                grid[x - 1][y] = -1
                heapq.heappush(q, (dis + 1, x - 1, y))

            # right
            if y + 1 < len(grid[x]) and grid[x][y + 1] != 2 and grid[x][y + 1] != -1:
                if grid[x][y + 1] == 3:
                    return dis
                grid[x][y + 1] = -1
                heapq.heappush(q, (dis + 1, x, y + 1))

            # bottom
            if x + 1 < len(grid) and grid[x + 1][y] != 2 and grid[x + 1][y] != -1:
                if grid[x + 1][y] == 3:
                    return dis
                grid[x + 1][y] = -1
                heapq.heappush(q, (dis + 1, x + 1, y))
            
        # print(grid)
        
