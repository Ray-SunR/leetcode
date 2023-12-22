class Solution:
    def dfs(self, matrix, x, y, visited):
        visited[x][y] = True
        # print('x: {}, y: {}'.format(x, y))
        # print(visited)
        # print(self.direction)
        self.result.append(matrix[x][y])
        direction = self.direction

        if direction == 'right' and not (y + 1 < len(matrix[x]) and not visited[x][y + 1]):
            self.direction = 'down'

        if direction == 'down' and not (x + 1 < len(matrix) and not visited[x + 1][y]):
            self.direction = 'left'

        if direction == 'left' and not (y - 1 >= 0 and not visited[x][y - 1]):
            self.direction = 'up'

        if direction == 'up' and not (x - 1 >= 0 and not visited[x - 1][y]):
            self.direction = 'right'
            
        direction = self.direction
        if direction == 'right' and y + 1 < len(matrix[x]) and not visited[x][y + 1]:
            self.dfs(matrix, x, y + 1, visited)

        if direction == 'down' and x + 1 < len(matrix) and not visited[x + 1][y]:
            self.dfs(matrix, x + 1, y, visited)

        if direction == 'left' and y - 1 >= 0 and not visited[x][y - 1]:
            self.dfs(matrix, x, y - 1, visited)

        if direction == 'up' and x - 1 >= 0 and not visited[x - 1][y]:
            self.dfs(matrix, x - 1, y, visited)
            
            
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        visited = [[False] * len(matrix[0]) for i in range(0, len(matrix))]
        self.result = []
        self.direction = 'right'
        self.dfs(matrix, 0, 0, visited)
        return self.result
        
