class Solution:   

    def isAlienSorted(self, words: List[str], order: str) -> bool:
        self.d = {}
        for idx in range(len(order)):
            self.d[order[idx]] = idx 
        return words == sorted(words, key=lambda word: [self.d[c] for c in word])
        
