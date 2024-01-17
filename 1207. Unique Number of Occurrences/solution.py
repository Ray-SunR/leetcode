class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        occurrences = set()
        d = {}
        for val in arr:
            if val not in d:
                d[val] = 0
            d[val] += 1
        for val in d:
            if d[val] in occurrences:
                return False
            else:
                occurrences.add(d[val])
        return True
