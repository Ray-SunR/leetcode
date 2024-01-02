from typing import List

class WordDistance:

    def __init__(self, wordsDict: List[str]):
        # first pass from left to right
        self.data = {}
        self.wordsDict = wordsDict
        self.ret = {}
        for word in wordsDict:
            ret = [0] * len(wordsDict)
            for i, w in enumerate(wordsDict):
                if w == word:
                    ret[i] = 0
                elif i - 1 >= 0:
                    ret[i] = ret[i - 1] + 1
                else:
                    ret[i] = len(wordsDict)
            self.ret[word] = {}
            # second pass from right to left
            i = len(wordsDict) - 1
            dis = float('inf')
            while i >= 0:
                if i + 1 < len(wordsDict):
                    ret[i] = min(ret[i + 1] + 1, ret[i])
                # self.ret[word][wordsDict[i]] = min(self.ret[word].get(wordsDict[i], float('inf')), ret[i])
                # if wordsDict[i] not in self.ret:
                    # self.ret[wordsDict[i]] = {}
                # self.ret[wordsDict[i]][word] = self.ret[word][wordsDict[i]]
                i -= 1

            self.data[word] = ret
            
        # print(self.ret)
    """
    @param word1: word1
    @param word2: word2
    @return: the shortest distance between two words
    """
    def shortest(self, word1: str, word2: str) -> int:
        # return self.ret[word1][word2]
        distances = self.data[word1]
        min_dis = float('inf')
        for i, dis in enumerate(distances):
            if self.wordsDict[i] == word2:
                min_dis = min(min_dis, dis)
        return min_dis
