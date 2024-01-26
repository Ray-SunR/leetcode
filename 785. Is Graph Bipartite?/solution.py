class Solution:
    def dfs(self, graph, i, color, colors):
        # print('i: {}, colors: {}'.format(i, colors))
        if colors[i] != -1:
            return colors[i] == color
        
        colors[i] = color
        for neighbor in graph[i]:
            if not self.dfs(graph, neighbor, 0 if color == 1 else 1, colors):
                return False

        return True
        
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colors = [-1] * len(graph)
        for i in range(len(graph)):
            if colors[i] == -1:
                if not self.dfs(graph, i, 0, colors):
                    return False
        return True