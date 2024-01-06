class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        # sort based on the end in asending order then by start in desending order
        intervals = sorted(intervals, key=lambda x: [x[1], -x[0]])
        print(intervals)
        ret = []
        for i, interval in enumerate(intervals):
            # [[1,3],[3,7],[8,9]] -> [[1,3],[3,7],[8,9]]
            # determine if the interval is fully covered by the current result
            if ret and interval[-2] <= ret[-2] <= interval[-1] and interval[-2] <= ret[-1] <= interval[-1]:
                continue
            # if only one side is overlapped
            elif ret and (interval[-2] <= ret[-2] <= interval[-1] or interval[-2] <= ret[-1] <= interval[-1]):
                # print('ret[-1]: {}, interval[0]: {}'.format(ret[-1], interval[0]))
                ret.append(interval[-1])
            # if no overlap
            else:
                # push the last two values of the largest interval
                ret.append(interval[1] - 1)
                ret.append(interval[1])
        # print(ret)
        return len(ret)
