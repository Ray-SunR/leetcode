class Solution:
    # key is to calcualte the max char count for all chars in the words2 
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        d = {}
        word2d = {}
        max_char_count = {}
        ret = []
        for word in words1:
            d[word] = {}
            for c in word:
                if c not in d[word]:
                    d[word][c] = 0
                d[word][c] += 1
        
        for word in words2:
            word2d[word] = {}
            for c in word:
                if c not in word2d[word]:
                    word2d[word][c] = 0
                word2d[word][c] += 1

        for word in word2d:
            for c in word:
                if c not in max_char_count or max_char_count[c] < word2d[word][c]:
                    max_char_count[c] = word2d[word][c]
                
        
        # print('d: {}, word2d: {}'.format(d, word2d))
        for word in words1:
            not_universal = False
            for c in max_char_count:
                if c not in d[word] or d[word][c] < max_char_count[c]:
                    not_universal = True
            if not not_universal:
                ret.append(word)

        return ret
