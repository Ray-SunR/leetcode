class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        ret = [0] * (k + 1)
        d = {}
        for log in logs:
            if log[0] not in d:
                d[log[0]] = set()
            d[log[0]].add(log[1])
        # print(d)
        for uid in d:
            ret[len(d[uid])] += 1
        return ret[1:]
