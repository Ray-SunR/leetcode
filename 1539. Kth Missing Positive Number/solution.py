class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        data = [None] * 1001
        for i in range(len(arr)):
            data[arr[i]] = arr[i]
        i = 1
        while i < len(data):
            if not data[i]:
                k -= 1
                if not k:
                    break
            i += 1
        if not k:
            return i
        # print('i: ' + str(i) + ' k: ' + str(k))
        return i - 1 + k
