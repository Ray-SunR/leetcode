class MovingAverage(object):
    """
    @param: size: An integer
    """
    def __init__(self, size):
        # do intialization if necessary
        self.window_size = size
        self.vals = []
        self.sum = 0

    """
    @param: val: An integer
    @return:  
    """
    def next(self, val):
        # write your code here
        if len(self.vals) == self.window_size:
            self.sum -= self.vals[0]
            self.vals.append(val)
            self.vals = self.vals[1:]
        else:
            self.vals.append(val)
        self.sum += self.vals[-1]
        return self.sum / min(len(self.vals), self.window_size)
            
        


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param = obj.next(val)
