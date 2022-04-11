class Solution:
    def buildGraph(self, accounts):
        graph = {}
        for account in accounts:
            name = account[0]
            emails = account[1:]
            if len(emails) >= 1:
                start = emails[0]
                graph[start] = [(start, name)] if start not in graph else graph[start]
                for email in emails[1:]:
                    # print('start: ' + start + ' ,to: ' + email)
                    graph[start].append((email, name))
                    if email in graph:
                        graph[email].append((start, name))
                    else:
                        graph[email] = [(start, name)]
        return graph
          
    def dfs(self, graph, email, ret):
        # print('visit: ' + email)
        self.visited.add(email)
        ret.add(email)
        for edge in graph[email]:
            if edge[0] not in self.visited:
                self.dfs(graph, edge[0], ret)
                
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        # build graph and then dfs
        graph = self.buildGraph(accounts)
        # print(graph)
        # dfs
        self.visited = set()
        self.ret = []
        for email in graph:
            ret = set()
            if email not in self.visited:
                self.dfs(graph, email, ret)
                self.ret.append([graph[email][0][1]] + sorted(list(ret)))
        return self.ret
