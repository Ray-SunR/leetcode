class Solution:
    def findLadders(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> List[List[str]]:
        wordList = set(wordList)
        if endWord not in wordList:
            return []
        if beginWord in wordList:
            wordList.remove(beginWord)
        ret = []
        q = [(1, beginWord, [beginWord])]
        min_dis = float("inf")
        while q:
            candidates = []
            while q:
                candidates.append(q.pop(0))
            for candidate in candidates:
                dis, word, paths = candidate
                if dis > min_dis:
                    continue
                if word == endWord:
                    ret.append(paths)
                    min_dis = min(min_dis, len(paths))
                    continue

                for i in range(len(word)):
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        new_word = word[:i] + c + word[i + 1 :]
                        if new_word in wordList and dis + 1 <= min_dis:
                            # print('new_word: {}'.format(new_word))
                            q.append((dis + 1, new_word, paths + [new_word]))
                if word in wordList:
                    wordList.remove(word)
        return ret
