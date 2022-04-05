class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])
        print(intervals)
        ret = []
        i = 0
        while i < len(intervals):
            interval = intervals[i]
            j = i + 1
            # print('i: ' + str(i))
            while j < len(intervals):
                # overlap
                if intervals[j][1] >= interval[1] and intervals[j][0] <= interval[1]:
                    interval[1] = intervals[j][1]
                    j += 1
                    i = j
                # contain
                elif intervals[j][1] <= interval[1]:
                    j += 1
                    i = j
                # not contain
                else:
                    i = j - 1
                    break
            ret.append(interval)
            i += 1
        return ret
