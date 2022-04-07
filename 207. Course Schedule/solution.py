class Solution:
    def dfs(self, graph, i, stk):
        stk.add(i)
        self.visited[i] = True
        if i in graph:
            for j in graph[i]:
                if j in stk:
                    return False
                if not self.visited[j]:
                    if not self.dfs(graph, j, stk):
                        return False
        stk.remove(i)
        return True
        
        
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # buid graph first
        graph = {}
        for i in range(len(prerequisites)):
            if prerequisites[i][1] not in graph:
                graph[prerequisites[i][1]] = []
            graph[prerequisites[i][1]].append(prerequisites[i][0])
        # print(graph)
        self.visited = [False] * numCourses
        stk = set()
        for i in graph:
            if not self.visited[i]:
                if not self.dfs(graph, i, stk):
                    return False
        return True
        o
