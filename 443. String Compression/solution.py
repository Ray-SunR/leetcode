class Solution:
    def compress(self, chars: List[str]) -> int:
        prob_p = 0
        new_p = 0
        while prob_p < len(chars):
            count = 0
            c = chars[prob_p]
            while prob_p < len(chars) and c == chars[prob_p]:
                prob_p += 1
                count += 1
            chars[new_p] = c
            new_p += 1
            if count > 1:
                count = list(str(count))
                for c in count:
                    chars[new_p] = c
                    new_p += 1
        return new_p
                
