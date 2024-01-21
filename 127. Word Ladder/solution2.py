class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        q = [(1, beginWord)]
        wordList = set(wordList)
        while q:
            dis, word = heapq.heappop(q)
            # print('dis: {}, word: {}'.format(dis, word))
            if word == endWord:
                return dis
            for i in range(len(word)):
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    new_word = word[:i] + ch + word[i + 1 :]
                    if new_word in wordList:
                        # print('new_word: {} pushed: '.format(new_word))
                        heapq.heappush(q, (dis + 1, new_word))
                        wordList.remove(new_word)
        return 0
