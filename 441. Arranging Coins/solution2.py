class Solution:
    def arrangeCoins(self, n: int) -> int:
        low = 1
        high = n
        while low <= high:
            mid = low + (high - low) // 2
            num = (1 + mid) * mid / 2
            if n - num < 0:
                high = mid - 1
            else:
                low = mid + 1
        return low - 1
        
                
        
