class SnakeGame:

    def __init__(self, width: int, height: int, foods) -> int:
        self.grid = [[0] * width for i in range(0, height)]
        for food in foods:
            if food[0] < len(self.grid) and food[1] < len(self.grid[food[0]]):
                self.grid[food[0]][food[1]] += 1
        self.snake = [[0, 0]]
        self.score = 0

    def game_over(self, x, y):
        if x >= len(self.grid) or y >= len(self.grid[0]) or x < 0 or y < 0:
            return True
        
        for coord in self.snake[1:]:
            if coord[0] == x and coord[1] == y:
                return True

        return False
    def print(self):
        copy_grid = [[self.grid[x][y] for y in range(len(self.grid[x]))] for x in range(len(self.grid))]
        for coord in self.snake:
            copy_grid[coord[0]][coord[1]] = 'X'
        
        s = ''
        for x in range(len(copy_grid)):
            row = ''
            for y in range(len(copy_grid[x])):
                row += str(copy_grid[x][y]) + ','
            row += '\n'
            s += row

        print(s)
        print(self.snake)
                
    """
    @param direction: the direction of the move
    @return: the score after the move
    """
    def move(self, direction: str) -> int:
        prev_tail_x, prev_tail_y = self.snake[-1][0], self.snake[-1][1]
        head_x, head_y = self.snake[0][0], self.snake[0][1]
        prev_x, prev_y = head_x, head_y
        if direction == 'l':
            head_y -= 1
        elif direction == 'u':
            head_x -= 1
        elif direction == 'r':
            head_y += 1
        else:
            head_x += 1
        self.snake[0][0] = head_x
        self.snake[0][1] = head_y
        # move the rest
        for i in range(1, len(self.snake)):
            temp = self.snake[i]
            self.snake[i] = [prev_x, prev_y]
            prev_x = temp[0]
            prev_y = temp[1]
            
        if self.game_over(self.snake[0][0], self.snake[0][1]):
            return -1
        # print(direction)
        # print('new_head_x: {}, new_head_y: {}'.format(self.snake[0][0], self.snake[0][1]))
        if self.grid[self.snake[0][0]][self.snake[0][1]] >= 1:
            self.grid[self.snake[0][0]][self.snake[0][1]] -= 1
            self.score += 1
            self.snake.append([prev_tail_x, prev_tail_y])
        # self.print()


        return self.score
