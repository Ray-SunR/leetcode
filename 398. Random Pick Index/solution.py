class Solution:

    def __init__(self, nums: List[int]):
        self.data = {}
        for idx in range(len(nums)):
            if nums[idx] in self.data:
                self.data[nums[idx]].append(idx)
            else:
                self.data[nums[idx]] = [idx]
        print(self.data)

    def pick(self, target: int) -> int:
        # print(target)
        return self.data[target][random.randint(0, len(self.data[target]) - 1)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
