class Solution:
    def dfs(self, idx, graph, visited, instack):
        visited[idx] = True
        for i in graph.get(idx, []):
            if i in instack:
                self.loop = True
                return
            if not visited[i]:
                visited[i] = True
                instack.add(i)
                self.dfs(i, graph, visited, instack)
                instack.remove(i)
        self.ret.insert(0, idx)
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = {}
        i = 0
        while i < numCourses:
            graph[i] = []
            i += 1
        for course in prerequisites:
            fr = course[1]
            to = course[0]
            if fr not in graph:
                graph[fr] = []
            graph[fr].append(to)
        # print(graph)
        visited = [False] * numCourses
        self.ret = []
        instack = set()
        
        self.loop = False
        for i in range(numCourses):
            if not visited[i]:
                instack.add(i)
                self.dfs(i, graph, visited, instack)
                instack.remove(i)
        return self.ret if not self.loop else []
        
