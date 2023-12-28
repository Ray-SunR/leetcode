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
        self.direction = ""
        self.tail_direction = ""
        self.score = 0
        self.snake = [[0, 0]]
        print(self.grid)

    def print(self):
        return
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

        print(self.direction)
        print(ss)
        print('------')
        # print('snake: {}, score: {}, direction: {}, tail_direction: {}'.format(self.snake, self.score, self.direction, self.tail_direction))

    """
    @param direction: the direction of the move
    @return: the score after the move
    """
    def move(self, direction: str) -> int:
        # self.print()
        # print(direction)

        prev_x = self.snake[0][0]
        prev_y = self.snake[0][1]
        self.direction = direction

        if self.tail_direction == "":
            self.tail_direction = direction
        if direction == "l":
            self.snake[0][1] = self.snake[0][1] - 1
        elif direction == "u":
            self.snake[0][0] = self.snake[0][0] - 1
        elif direction == "r":
            self.snake[0][1] = self.snake[0][1] + 1
        else:
            self.snake[0][0] = self.snake[0][0] + 1
        
        headx = self.snake[0][0]
        heady = self.snake[0][1]
        if not (headx >= 0 and headx < self.height and heady >= 0 and heady < self.width):
            return -1


        if self.grid[headx][heady] >= 1:
            self.grid[headx][heady] -= 1
            self.score += 1
            tail = self.snake[-1]
            new_coord = [tail[0], tail[1]]
            if self.tail_direction == "l":
                new_coord[1] += 1
            elif self.tail_direction == "t":
                new_coord[0] += 1
            elif self.tail_direction == "r":
                new_coord[1] -= 1
            else:
                new_coord[0] -= 1
            self.snake.append(new_coord)
        for i in range(1, len(self.snake)):
            temp_x = self.snake[i][0]
            temp_y = self.snake[i][1]
            self.snake[i][0] = prev_x
            self.snake[i][1] = prev_y
            prev_x = temp_x
            prev_y = temp_y

        for coord in self.snake[1:]:
            if coord[0] == headx and coord[1] == heady:
                return -1
        self.print()
        # print('------')
        return self.score
        
        
