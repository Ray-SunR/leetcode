class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        result = []
        i = 0
        start, end = newInterval

        # Add all intervals ending before newInterval starts
        while i < len(intervals) and intervals[i][1] < start:
            result.append(intervals[i])
            i += 1

        # Merge intervals that overlap with newInterval
        while i < len(intervals) and intervals[i][0] <= end:
            start = min(start, intervals[i][0])
            end = max(end, intervals[i][1])
            i += 1
        result.append([start, end])

        # Add the remaining intervals
        result.extend(intervals[i:])

        return result
