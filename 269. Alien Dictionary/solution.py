from typing import (
    List,
)

class Solution:
    def dfs(self, graph, visited, c, instack, ret):
        print(c)
        visited[c] = True
        for neighbor in graph[c]:
            if neighbor in instack:
                # loop
                return True
            if not visited[neighbor]:
                instack.add(neighbor)
                if self.dfs(graph, visited, neighbor, instack, ret):
                    return True
                instack.remove(neighbor)
        ret.insert(0, c)
        return False

    """
    @param words: a list of words
    @return: a string which is correct order
    """
    def alien_order(self, words: List[str]) -> str:
        graph = {c : set() for word in words for c in word  }

        for i in range(len(words) - 1):
            w1 = words[i]
            w2 = words[i + 1]
            if len(w1) > len(w2) and w1.startswith(w2):
                return ""
            j = 0
            while j < min(len(w1), len(w2)):
                if w1[j] != w2[j]:
                    graph[w1[j]].add(w2[j])
                    break
                j += 1
            i += 1
        visited = { c: False for c in graph }
        instack = set()
        ret = []
        for c in 'abcdefghijklmnokpqrstuvwxyz'[::-1]:
            if c in graph and not visited[c]:
                instack.add(c)
                if self.dfs(graph, visited, c, instack, ret):
                    return ""
                instack.remove(c)
        return ''.join(ret)
        

            
s = Solution()
print(s.alien_order(["wrt","wrf","er","ett","rftt"]))
print(s.alien_order(["z","x"]))
print(s.alien_order(["ab","adc"]))
# w -> r
'''
w -> [e]
t -> [f]
r -> [t]
e -> [r]

'''
# b -> d