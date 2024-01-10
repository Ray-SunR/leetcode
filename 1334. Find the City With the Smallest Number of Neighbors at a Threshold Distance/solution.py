class Solution:
    def bfs(self, i, graph, threshold):
        visited = [False] * len(graph)
        q = []
        heapq.heappush(q, (0, i))

        min_distance = [float('inf')] * len(graph)
        min_distance[i] = 0
        while q:
            dis, city = heapq.heappop(q)
            # print('city: {}, dis: {}'.format(city, dis))
            for weight, neighbor in graph[city]:
                # print('neighbor: {}, weight: {}'.format(neighbor, weight))
                new_dis = dis + weight
                if new_dis <= threshold and new_dis < min_distance[neighbor]:
                    heapq.heappush(q, (new_dis, neighbor))
                    min_distance[neighbor] = new_dis
        ret = 0
        for i in range(len(graph)):
            if min_distance[i] <= threshold:
                ret += 1
        return ret - 1
            
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        # build graph
        graph = {}
        for i in range(n):
            graph[i] = []
        
        for edge in edges:
            start = edge[0]
            to = edge[1]
            weight = edge[2]
            graph[start].append((weight, to))
            graph[to].append((weight, start))
        
        # print(graph)
        min_cities = float('inf')
        min_city = None
        for i in range(n):
            num_cities = self.bfs(i, graph, distanceThreshold)
            # print(num_cities)
            if num_cities <= min_cities:
                min_cities = num_cities
                min_city = i
        return min_city
            
        
