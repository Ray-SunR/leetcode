lass Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        window_sum = 0
        ret = [-1] * len(nums)
        i = k
        if i < len(nums) - k:
            b = i - k
            e = i + k
            while b <= e:
                window_sum += nums[b]
                b += 1
            ret[i] = window_sum // (k * 2 + 1)
        i += 1
        while i < len(nums) - k:
            b = i - k - 1
            e = i + k
            # print('num[e]: {}, num[b]: {}'.format(nums[e], nums[b]))
            window_sum += nums[e]
            window_sum -= nums[b]
            
            ret[i] = window_sum // (k * 2 + 1)
            i += 1

                
        return ret
            
