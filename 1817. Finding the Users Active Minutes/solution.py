class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        ret = [0] * k
        d = {}
        for log in logs:
            d[log[0]] = d.get(log[0], set())
            d[log[0]].add((log[0], log[1]))
        for i in d:
            if len(d[i]) <= k and len(d[i]) >= 1:
                ret[len(d[i]) - 1] = ret[len(d[i]) - 1] + 1
        # print(d)
        return ret
            
