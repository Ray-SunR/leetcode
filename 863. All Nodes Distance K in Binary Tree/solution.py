# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, node, graph):
        if not node:
            return
        if node.val not in graph:
            graph[node.val] = []
        if node.left:
            graph[node.val].append(node.left.val)
            if node.left.val not in graph:
                graph[node.left.val] = []
            graph[node.left.val].append(node.val)
        if node.right:
            graph[node.val].append(node.right.val)
            if node.right.val not in graph:
                graph[node.right.val] = []
            graph[node.right.val].append(node.val)
        self.dfs(node.left, graph)
        self.dfs(node.right, graph)

    def find_distance_k(self, node_val, k, graph, ret, visited):
        if k == 0:
            ret.append(node_val)
            visited[node_val] = True
            return
        visited[node_val] = True
        neighbors = graph.get(node_val, [])
        for neighbor in neighbors:
            if not visited.get(neighbor, False):
                self.find_distance_k(neighbor, k - 1, graph, ret, visited)
        
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        # build a graph
        graph = {}
        self.dfs(root, graph)
        # print(graph)

        ret = []
        visited = {target.val: True}
        
        self.find_distance_k(target.val, k, graph, ret, visited)
        return ret
        '''
        [0,2,1,null,null,3]
        3
        3

                0
            2       1
                 3

        '''
        
        
