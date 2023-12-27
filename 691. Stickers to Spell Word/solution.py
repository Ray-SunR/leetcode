class Solution:
    def helper(self, stickers, idx, target):
        if target == "":
            return 0
        if idx == len(stickers):
            return -1

        # print('idx: {}, sticker: {}, target: {}'.format(idx, stickers[idx], target))
        key = (idx, target)
        if key in self.memo:
            return self.memo[key]
        # option 1: not use this sticker at all
        result = self.helper(stickers, idx + 1, target)

        # option 2: use the current sticker
        sticker = stickers[idx]
        target_copy = target
        found = False
        for c in sticker:
            index = target_copy.find(c)
            if index != -1:
                target_copy = target_copy[:index] + target_copy[index + 1:]
                found = True
        if found:
            v = self.helper(stickers, idx, target_copy)
            if v != -1:
                if result == -1:
                    result = 1 + v
                else:
                    result = min(result, 1 + v)
            # result = min(result, 1 + self.helper(stickers, idx, target_copy))
            # means there are some chars in the sticker that can be used

            
        self.memo[key] = result
        # self.ret = min(self.ret, result)
        return result
        
    def minStickers(self, stickers: List[str], target: str) -> int:
        self.memo = {}
        self.ret = float(inf)
        result = self.helper(stickers, 0, target)
        return result if result != -1 else -1
        # print(self.memo)
        # return -1 if self.ret == float(inf) else self.ret
