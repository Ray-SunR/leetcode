from typing import (
    List,
)
import heapq

class Solution:
    """
    @param maze_map: a 2D grid
    @return: return the minium distance
    """
    def get_min_distance(self, maze_map: List[List[int]]) -> int:
        '''
         1    0    0   3
        -2    0   -1  -3
         2    2    0   0 
        '''
        q = []
        visited = [[False] * len(maze_map[i]) for i in range(len(maze_map))]
        d = {}
        for x in range(len(maze_map)):
            for y in range(len(maze_map[x])):
                if maze_map[x][y] == -2:
                    heapq.heappush(q, (0, x, y))
                    visited[x][y] = True
                
                if maze_map[x][y] not in d:
                    d[maze_map[x][y]] = []
                # tracking the neighbors with the same value
                if maze_map[x][y] > 0:
                    d[maze_map[x][y]].append((x, y))
        while q:
            dist, x, y = heapq.heappop(q)
            # print('dist: {}, x: {}, y: {}'.format(dist, x, y))
            if maze_map[x][y] == -3:
                return dist
            
            # left
            if y - 1 >= 0 and not visited[x][y - 1] and maze_map[x][y - 1] != -1:
                heapq.heappush(q, (dist + 1, x, y - 1))
                visited[x][y - 1] = True
            # top
            if x - 1 >= 0 and not visited[x - 1][y] and maze_map[x - 1][y] != -1:
                heapq.heappush(q, (dist + 1, x - 1, y))
                visited[x - 1][y] = True
            # right
            if y + 1 < len(maze_map[x]) and not visited[x][y + 1] and maze_map[x][y + 1] != -1:
                heapq.heappush(q, (dist + 1, x, y + 1))
                visited[x][y + 1] = True
            # bottom
            if x + 1 < len(maze_map) and not visited[x + 1][y] and maze_map[x + 1][y] != -1:
                heapq.heappush(q, (dist + 1, x + 1, y))
                visited[x + 1][y] = True

            # neighbors with same value
            neighbors = d.get(maze_map[x][y], [])
            for neighbor in neighbors:
                if not visited[neighbor[0]][neighbor[1]]:
                    heapq.heappush(q, (dist + 1, neighbor[0], neighbor[1]))
                    visited[neighbor[0]][neighbor[1]] = True
            if maze_map[x][y] in d:
                del d[maze_map[x][y]]
        return -1

    def get_min_distance_2(self, maze_map: List[List[int]]) -> int:
        '''
         1    0    0   3
        -2    0   -1  -3
         2    2    0   0 
        '''
        q = []
        visited = [[False] * len(maze_map[i]) for i in range(len(maze_map))]
        d = {}
        for x in range(len(maze_map)):
            for y in range(len(maze_map[x])):
                if maze_map[x][y] == -2:
                    q.append((0, x, y))
                    visited[x][y] = True
                
                if maze_map[x][y] not in d:
                    d[maze_map[x][y]] = []
                # tracking the neighbors with the same value
                if maze_map[x][y] > 0:
                    d[maze_map[x][y]].append((x, y))
        while q:
            candidates = []
            while q:
                candidates.append(q.pop(0))
            
            for candidate in candidates:
                dist, x, y = candidate
                # print('dist: {}, x: {}, y: {}'.format(dist, x, y))
                if maze_map[x][y] == -3:
                    return dist
            
                # left
                if y - 1 >= 0 and not visited[x][y - 1] and maze_map[x][y - 1] != -1:
                    q.append((dist + 1, x, y - 1))
                    visited[x][y - 1] = True
                # top
                if x - 1 >= 0 and not visited[x - 1][y] and maze_map[x - 1][y] != -1:
                    q.append((dist + 1, x - 1, y))
                    visited[x - 1][y] = True
                # right
                if y + 1 < len(maze_map[x]) and not visited[x][y + 1] and maze_map[x][y + 1] != -1:
                    q.append((dist + 1, x, y + 1))
                    visited[x][y + 1] = True
                # bottom
                if x + 1 < len(maze_map) and not visited[x + 1][y] and maze_map[x + 1][y] != -1:
                    q.append((dist + 1, x + 1, y))
                    visited[x + 1][y] = True

                # neighbors with same value
                neighbors = d.get(maze_map[x][y], [])
                for neighbor in neighbors:
                    if not visited[neighbor[0]][neighbor[1]]:
                        q.append((dist + 1, neighbor[0], neighbor[1]))
                        visited[neighbor[0]][neighbor[1]] = True
                if maze_map[x][y] in d:
                    del d[maze_map[x][y]]

        return -1

