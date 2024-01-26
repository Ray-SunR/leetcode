class Solution:
    def dfs(self, i, n, non_edges, colors, color):
        colors[i] = color

        for neighbor in non_edges[i]:
            if colors[neighbor] == -1:
                if not self.dfs(neighbor, n, non_edges, colors, 0 if color == 1 else 1):
                    return False
            elif colors[neighbor] == color:
                # print('non-edge neighbor: {} of {} is the same color'.format(neighbor, i))
                return False
        return True
        
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        # build a graph each person is a node and connect to the rest of the people
        # if a dislikes b, them remove the edge. That implicitly means, when checking edges
        # we don't need to consider the edge in dislikes
        if n == 1:
            return True
        non_edges = {}
        colors = [-1] * (n + 1)
        for dislike in dislikes:
            fr = dislike[0]
            to = dislike[1]
            if fr not in non_edges:
                non_edges[fr] = set()
            if to not in non_edges:
                non_edges[to] = set()
            non_edges[fr].add(to)
            non_edges[to].add(fr)
        for i in non_edges:
            if colors[i] == -1:
                if not self.dfs(i, n, non_edges, colors, 0):
                    return False
        # print(group_id)
        # print(visited)
        return True



