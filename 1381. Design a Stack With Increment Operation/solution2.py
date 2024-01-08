class CustomStack:

    def __init__(self, maxSize: int):
        self.data = []
        self.max_size = maxSize

    def push(self, x: int) -> None:
        if len(self.data) == self.max_size:
            return None
        self.data.append(x)

    def pop(self) -> int:
        if not self.data:
            return -1
        return self.data.pop()

    def increment(self, k: int, val: int) -> None:
        limit = min(k, len(self.data))
        i = 0
        while i < limit:
            self.data[i] += val
            i += 1
        


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
