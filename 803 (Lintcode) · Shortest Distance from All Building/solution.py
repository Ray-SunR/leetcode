from typing import (
    List,
)

class Solution:
    def bfs(self, grid, x, y):
        q = [(0, x, y)]
        visited = [[False] * len(grid[i]) for i in range(len(grid))]
        visited[x][y] = True
        total_dis = 0
        while q:
            dis, xx, yy = q.pop(0)
            if grid[xx][yy] == 1:
                total_dis += dis
                continue
            # left
            if yy - 1 >= 0 and not visited[xx][yy - 1] and grid[xx][yy - 1] != 2:
                q.append((dis + 1, xx, yy - 1))
                visited[xx][yy - 1] = True

            # top
            if xx - 1 >= 0 and not visited[xx - 1][yy] and grid[xx - 1][yy] != 2:
                q.append((dis + 1, xx - 1, yy))
                visited[xx - 1][yy] = True
            
            # right
            if yy + 1 < len(grid[x]) and not visited[xx][yy + 1] and grid[xx][yy + 1] != 2:
                q.append((dis + 1, xx, yy + 1))
                visited[xx][yy + 1] = True

            # bottom
            if xx + 1 < len(grid) and not visited[xx + 1][yy] and grid[xx + 1][yy] != 2:
                q.append((dis + 1, xx + 1, yy))
                visited[xx + 1][yy] = True
        # print('x: {}, y: {}, visited: {}'.format(x, y, visited))
        possible = True
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if not visited[i][j] and grid[i][j] == 1:
                    possible = False
                    break
        return total_dis, possible

    """
    @param grid: the 2D grid
    @return: the shortest distance
    """
    def shortest_distance(self, grid: List[List[int]]) -> int:
        min_distance = float('inf')
        calculated = [[False] * len(grid[i]) for i in range(len(grid))]
        for x in range(len(grid)):
            for y in range(len(grid[x])):
                if grid[x][y] == 0 and not calculated[x][y]:
                    calculated[x][y] = True
                    total_dis, possible = self.bfs(grid, x, y)
                    if not possible:
                        # print('x: {}, y: {} not possible'.format(x, y))
                        continue
                    min_distance = min(total_dis, min_distance)

        return -1 if min_distance == float('inf') else min_distance

'''
[1,1,1,1,1,0]
[0,0,0,0,0,1]
[0,1,1,0,0,1]
[1,0,0,1,0,1]
[1,0,1,0,0,1]
[1,0,0,0,0,1]
[0,1,1,1,1,0]]
'''
