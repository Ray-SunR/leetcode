ass Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: (x[0], x[1]))
        ret = []
        i = 0
        while i < len(intervals):
            interval = intervals[i]
            j = i + 1
            while j < len(intervals):
                if intervals[i][0] <= intervals[j][0] and intervals[i][1] >= intervals[j][1]:
                    j += 1
                elif intervals[j][0] > intervals[i][1]:
                    # no coverage
                    break
                else:
                    interval[1] = intervals[j][1]
                    j += 1
            ret.append(interval)
            i = j
        return ret
        
