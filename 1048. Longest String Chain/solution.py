class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        graph = {word: set() for word in words}
        q = [(-1, word) for word in words]
        heapq.heapify(q)
        seen = {word: 1 for word in words}
        ret = 1
        while q:
            # print(q)
            length, word = heapq.heappop(q)
            length = -length
            if length < seen[word]:
                continue
            ret = max(length, ret)
            for i, c in enumerate(word):
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    new_word = word[:i] + ch + c + word[i + 1 :]
                    if new_word in seen and length + 1 > seen[new_word]:
                        # print(new_word)
                        heapq.heappush(q, (-(length + 1), new_word))
                        seen[new_word] = length + 1
                    new_word = word[:i] + c + ch + word[i + 1 :]
                    if new_word in seen and length + 1 > seen[new_word]:
                        # print(new_word)
                        heapq.heappush(q, (-(length + 1), new_word))
                        seen[new_word] = length + 1
        return ret
