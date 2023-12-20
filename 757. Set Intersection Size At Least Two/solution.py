class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], -x[0]))
        res = []
        for interval in intervals:
            if res and interval[0] <= res[-2]:
                continue
            if res and interval[0] <= res[-1]:
                res.append(interval[1])
            else:
                res.append(interval[-1] - 1)
                res.append(interval[-1])
        return len(res)
