from typing import (
    List,
)


class Solution:
    """
    @param grid: a 2D grid
    @return: the minimize travel distance
    """

    def min_total_distance(self, grid: List[List[int]]) -> int:
        ret = float("inf")
        for xx in range(len(grid)):
            for yy in range(len(grid[xx])):
                total_dis = 0
                q = [(0, xx, yy)]
                visited = set()
                visited.add((xx, yy))
                while q:
                    dis, x, y = q.pop(0)
                    if total_dis >= ret:
                        break
                    # print('x: {}, y: {}, dis: {}'.format(x, y, dis))
                    if grid[x][y] == 1:
                        total_dis += dis
                    # left
                    if y - 1 >= 0 and (x, y - 1) not in visited:
                        q.append((dis + 1, x, y - 1))
                        visited.add((x, y - 1))
                    # top
                    if x - 1 >= 0 and (x - 1, y) not in visited:
                        q.append((dis + 1, x - 1, y))
                        visited.add((x - 1, y))
                    # right
                    if y + 1 < len(grid[x]) and (x, y + 1) not in visited:
                        q.append((dis + 1, x, y + 1))
                        visited.add((x, y + 1))
                    # bbottom
                    if x + 1 < len(grid) and (x + 1, y) not in visited:
                        q.append((dis + 1, x + 1, y))
                        visited.add((x + 1, y))
                # print(dists)
                if not q:
                    ret = min(ret, total_dis)

        return ret

        """
        [1,1,0]
        [1,1,0]
        [0,1,0]
        """
