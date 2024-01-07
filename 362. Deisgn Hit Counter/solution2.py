import bisect
class HitCounter:

    def __init__(self):
        self.d = []

    """
    @param timestamp: the timestamp
    @return: nothing
    """
    def hit(self, timestamp: int):
        self.d.append(timestamp)

    """
    @param timestamp: the timestamp
    @return: the count of hits in recent 300 seconds
    """
    def get_hits(self, timestamp: int) -> int:
        idx_left = bisect.bisect_right(self.d, timestamp - 300)
        idx_right = bisect.bisect_right(self.d, timestamp)
        # print('idx_left: {}, idx_right: {}'.format(idx_left, idx_right))
        return idx_right - idx_left
