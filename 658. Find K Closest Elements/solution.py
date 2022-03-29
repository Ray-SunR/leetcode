class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        i = bisect_left(arr, x)
        left = i - 1
        right = i
        ret = []
        while k and left >= 0 and right < len(arr):
            if abs(arr[left] - x) < abs(arr[right] - x) or (abs(arr[left] - x) == abs(arr[right] - x) and arr[left] < arr[right]):
                ret.append(arr[left])
                left -= 1
            else:
                ret.append(arr[right])
                right += 1
            
            k -= 1

        if left >= 0:
            while k:
                ret.append(arr[left])
                left -= 1
                k -= 1
        if right < len(arr):
            while k:
                ret.append(arr[right])
                right += 1
                k -= 1
            
        return sorted(ret)
