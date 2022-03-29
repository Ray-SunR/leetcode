class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        ret = 0
        l = 0
        count = 0
        for i in range(len(nums)):
            # print(i)
            # print(l)
            # print(k)
            # print('------')
            if nums[i] % 2 == 1:
                k -= 1
                count = 0 
            while k == 0:
                if nums[l] % 2 == 1:
                    k += 1
                count += 1
                l += 1
            ret += count
        return ret
