class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        d = {}
        for log in logs:
            if log[0] not in d:
                d[log[0]] = set()
            d[log[0]].add(log[1])
        ret = [0] * k
        for i in d:
            ret[len(d[i]) - 1] += 1
        return ret
