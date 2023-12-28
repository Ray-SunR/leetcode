import bisect

class HitCounter:
    def __init__(self):
        self.times = []

    """
    @param timestamp: the timestamp
    @return: nothing
    """
    def hit(self, timestamp: int):
        self.times.append(timestamp)
        

    """
    @param timestamp: the timestamp
    @return: the count of hits in recent 300 seconds
    """
    def get_hits(self, timestamp: int) -> int:
        idx_begin = bisect.bisect_right(self.times, timestamp - 300)
        idx_end = bisect.bisect_right(self.times, timestamp)
        return idx_end - idx_begin
