class Solution:
    def getLeftAndRight(self, flowerbed, idx):
        left_idx = idx - 1
        right_idx = idx + 1
        left = 0
        right = 0
        if left_idx >= 0:
            left = flowerbed[left_idx]
        if right_idx < len(flowerbed):
            right = flowerbed[right_idx]
        return (left, right)
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        for idx in range(len(flowerbed)):
            if flowerbed[idx] == 0:
                left, right = self.getLeftAndRight(flowerbed, idx)
                # print('left: ' + str(left) + ' right: ' + str(right) + ' idx: ' + str(idx))
                if left == 0 and right == 0:
                    flowerbed[idx] = 1
                    if n > 0:
                        n -= 1
            if n == 0:
                return True
                    
        return n == 0
