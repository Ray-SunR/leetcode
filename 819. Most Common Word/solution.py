class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        banned = set(banned)
        counter = {}
        for w in paragraph.split(" "):
            w = w.lower()
            sanitized_word = ""
            for c in w:
                if ord(c) >= ord("a") and ord(c) <= ord("z"):
                    sanitized_word += c
                elif sanitized_word:
                    if sanitized_word in banned:
                        continue
                    if sanitized_word not in counter:
                        counter[sanitized_word] = 0
                    counter[sanitized_word] += 1
                    sanitized_word = ""
            if sanitized_word:
                if sanitized_word in banned:
                    continue
                if sanitized_word not in counter:
                    counter[sanitized_word] = 0
                counter[sanitized_word] += 1
        # print(counter)
        pq = []
        for w in counter:
            heapq.heappush(pq, (-counter[w], w))
        return pq[0][1]
