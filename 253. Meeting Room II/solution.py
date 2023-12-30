from typing import (
    List,
)
from lintcode import (
    Interval,
)
import heapq

"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """
    def min_meeting_rooms(self, intervals: List[Interval]) -> int:
        # Write your code here
        # [(0,30),(5,10),(15,20)] -> [(5, 10), (15, 20), (0, 30)]
        # [(0,30),(5,10),(10,20),(15,20)] -> # sort by stating time
        # use a min heap that sort the end time, the heap tells which meeting ends first?
        intervals = sorted(intervals, key=lambda x: (x.start, x.end))
        heap = []
        ret = 0
        for interval in intervals:
            if heap and interval.start >= heap[0]:
                # pop all meetings that already end
                while heap and interval.start >= heap[0]:
                    heapq.heappop(heap)
            heapq.heappush(heap, interval.end)
            # print(heap)
            ret = max(ret, len(heap))
        return ret

