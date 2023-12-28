class SnakeGame:
    from typing import (
        List,
    )
    def __init__(self, width: int, height: int, foods: List[List[int]]) -> int:
        self.width = width
        self.height = height
        self.grid = [[0] * width for i in range(height)]
        for food in foods:
            if food[0] < len(self.grid) and food[1] < len(self.grid[0]):
                self.grid[food[0]][food[1]] += 1
        self.score = 0
        self.snake = [[0, 0]]
        print(self.grid)

    def print(self):
        # return
        print(self.snake)
        copied_grid = [x[:] for x in self.grid]
        copied_grid[self.snake[0][0]][self.snake[0][1]] = 'H'
        for coord in self.snake[1:]:
            copied_grid[coord[0]][coord[1]] = 'X'
        ss = ''
        for i in range(len(copied_grid)):
            s = ''
            for j in range(len(copied_grid[i])):
                s = s + ',' + str(copied_grid[i][j])
            s = s + '\n'
            ss += s

        print(ss)
        print('------')

    """
    @param direction: the direction of the move
    @return: the score after the move
    """
    def move(self, direction: str) -> int:
        # self.print()
        # print(direction)
        headx,heady = self.snake[0][0], self.snake[0][1]
        if direction == "l":
            heady = self.snake[0][1] - 1
        elif direction == "u":
            headx = self.snake[0][0] - 1
        elif direction == "r":
            heady = self.snake[0][1] + 1
        else:
            headx = self.snake[0][0] + 1
        
        if not (headx >= 0 and headx < self.height and heady >= 0 and heady < self.width):
            return -1

        if self.grid[headx][heady] >= 1:
            self.grid[headx][heady] -= 1
            self.score += 1
            self.snake.insert(0, [headx, heady])
        else:
            for i in range(0, len(self.snake)):
                temp_x = self.snake[i][0]
                temp_y = self.snake[i][1]
                self.snake[i][0] = headx
                self.snake[i][1] = heady
                headx = temp_x
                heady = temp_y

        coords = set()
        for coord in self.snake:
            tup = (coord[0], coord[1])
            if tup not in coords:
                coords.add(tup)
            else:
                return -1
        self.print()
        # print('------')
        return self.score
        
        
