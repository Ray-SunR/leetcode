# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def peakIndex(self, mountain_arr):
        l = 0
        h = mountain_arr.length() - 1
        while l < h:
            

            mid = l + (h - l) // 2
            mid_left = mid - 1
            mid_right = mid + 1

            val = mountain_arr.get(mid)
            # print('l: {}, h: {}, val: {}, mid: {}'.format(l, h, val, mid))
            val_left = mountain_arr.get(mid_left) if mid_left >= 0 else float(-inf)
            val_right = mountain_arr.get(mid_right) if mid_right < mountain_arr.length() else float(-inf)
            if val > val_left and val > val_right:
                return mid
            elif val < val_left:
                h = mid - 1
            else:
                l = mid + 1
        return l

    def bi_search(self, arr, peak_index, target):
        low_left = 0
        high_left = peak_index - 1
        while low_left <= high_left:
            mid = low_left + (high_left - low_left) // 2
            val = arr.get(mid)
            if val == target:
                return mid
            elif val > target:
                high_left = mid - 1
            else:
                low_left = mid + 1
        
        low_right = peak_index + 1
        high_right = arr.length() - 1
        while low_right <= high_right:
            mid = low_right + (high_right - low_right) // 2
            val = arr.get(mid)
            if val == target:
                return mid
            elif val > target:
                low_right = mid + 1
            else:
                high_right = mid - 1
        return -1
        
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        # find peak element
        peak_index = self.peakIndex(mountain_arr)
        if mountain_arr.get(peak_index) == target:
            return peak_index

        # perform bisearch on the first half and second half
        return self.bi_search(mountain_arr, peak_index, target)
        
