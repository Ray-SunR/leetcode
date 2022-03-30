class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        q = [(beginWord, 1, [beginWord])]
        # ret = math.inf
        visited = set()
        visited.add(beginWord)
        dic = set(wordList)
        while len(q):
            w = q.pop(0)
            word = w[0]
            # print(word)
            length = w[1]
            if word == endWord:
                # print(w[2])
                # ret = min(ret, length)
                return length
            else:
                word = list(word)
                # print(word)
                for i in range(len(word)):
                    # print(i)
                    old_char = word[i]
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        word[i] = c
                        new_word = ''.join(word)
                        # print(new_word)
                        if new_word not in visited and new_word in dic:
                            new_paths = w[2].copy()
                            new_paths.append(new_word)
                            q.append((new_word, length + 1, new_paths))
                            visited.add(new_word)
                    word[i] = old_char
        return 0
