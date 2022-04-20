class Solution:
    def canJump(self, nums: List[int]) -> bool:
        q = [0]
        visited = set([0])
        while q:
            new = []
            while q:
                i = q.pop()
                if i + nums[i] >= len(nums) - 1:
                    return True
                v = nums[i]
                while v:
                    if i + v not in visited:
                        new.append(i + v)
                        visited.add(i + v)
                    v -= 1
            q = new
        return False
                
