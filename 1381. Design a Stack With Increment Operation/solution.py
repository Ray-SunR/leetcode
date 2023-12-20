class CustomStack:

    def __init__(self, maxSize: int):
        self.max_size = maxSize
        self.data = []
        

    def push(self, x: int) -> None:
        if len(self.data) == self.max_size:
            return
        self.data.append(x)

    def pop(self) -> int:
        if len(self.data) == 0:
            return -1
        return self.data.pop()
        

    def increment(self, k: int, val: int) -> None:
        # print(self.data)
        # print(k)
        for i in range(0, k if len(self.data) >= k else len(self.data)):
            # print(i)
            self.data[i] += val



# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
