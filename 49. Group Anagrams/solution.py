ass Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for s in strs:
            sorted_str = ''.join(sorted(s)) 
            if sorted_str not in d:
                d[sorted_str] = []
            d[sorted_str].append(s)
        ret = []
        for value in d.values():
            ret.append(value)
        return ret
