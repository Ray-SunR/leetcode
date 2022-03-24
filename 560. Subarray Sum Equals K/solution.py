class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        d = {}
        answer = 0
        for num in nums:
            prefix_sum += num
            if prefix_sum - k in d:
                answer += d[prefix_sum - k]
            if prefix_sum in d:
                d[prefix_sum] += 1
            else:
                d[prefix_sum] = 1
        return answer
