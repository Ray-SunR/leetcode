class Solution:
    def jump(self, nums: List[int]) -> int:
        # bfs
        q = []
        q.append(0)
        step = 0
        if len(nums) == 1:
            return 0
        visited = set()
        visited.add(0)
        while q:
            step += 1
            new = []
            # print(q)
            while q:
                i = q.pop()
                if i + nums[i] >= len(nums) - 1:
                    return step
                v = nums[i]
                while v:
                    if i + v not in visited:
                        new.append(i + v)
                        visited.add(i + v)
                    v -= 1
            q = new
        return -1
