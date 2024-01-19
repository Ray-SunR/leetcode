from typing import (
    List,
)


class Solution:
    """
    @param rooms: m x n 2D grid
    @return: nothing
    """

    def walls_and_gates(self, rooms: List[List[int]]):
        q = []
        for x in range(len(rooms)):
            for y in range(len(rooms[x])):
                if rooms[x][y] == 0:
                    q.append((0, x, y))

        print(q)
        while q:
            dis, x, y = q.pop()
            if y == 20:
                print("x: {}, y: {}, dis: {}, room: {}".format(x, y, dis, rooms[x][y]))
            # left
            if y - 1 >= 0 and rooms[x][y - 1] != -1 and rooms[x][y - 1] > dis + 1:
                q.append((dis + 1, x, y - 1))
                rooms[x][y - 1] = dis + 1
            # top
            if x - 1 >= 0 and rooms[x - 1][y] != -1 and rooms[x - 1][y] > dis + 1:
                q.append((dis + 1, x - 1, y))
                rooms[x - 1][y] = dis + 1
            # right
            if (
                y + 1 < len(rooms[x])
                and rooms[x][y + 1] != -1
                and rooms[x][y + 1] > dis + 1
            ):
                q.append((dis + 1, x, y + 1))
                rooms[x][y + 1] = dis + 1
            # bottom
            if (
                x + 1 < len(rooms)
                and rooms[x + 1][y] != -1
                and rooms[x + 1][y] > dis + 1
            ):
                q.append((dis + 1, x + 1, y))
                rooms[x + 1][y] = dis + 1

        print(rooms)


s = Solution()
s.walls_and_gates(
    [
        [
            0,
            2147483647,
            2147483647,
            0,
            2147483647,
            0,
            -1,
            2147483647,
            -1,
            0,
            0,
            -1,
            -1,
            2147483647,
            -1,
            2147483647,
            2147483647,
            0,
            2147483647,
            2147483647,
            0,
            0,
            -1,
            2147483647,
            -1,
            2147483647,
            -1,
            2147483647,
            2147483647,
            0,
            0,
            0,
        ],
        [
            0,
            2147483647,
            0,
            2147483647,
            0,
            0,
            -1,
            -1,
            -1,
            2147483647,
            2147483647,
            2147483647,
            2147483647,
            2147483647,
            -1,
            2147483647,
            0,
            0,
            2147483647,
            2147483647,
            2147483647,
            0,
            0,
            0,
            0,
            -1,
            2147483647,
            -1,
            2147483647,
            0,
            2147483647,
            0,
        ],
    ]
)
