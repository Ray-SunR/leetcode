class Trie:
    def __init__(self):
        self.children = {}
        self.c = None
        self.is_word = False
        self.index = -1


class WordFilter:
    def build_prefix_trie(self, words):
        for i, w in enumerate(words):
            node = self.prefix_trie

            for c in w:
                if c not in node.children:
                    node.children[c] = Trie()
                    node.children[c].c = c
                node = node.children[c]
            node.is_word = True
            node.c = w
            node.index = i

    def build_suffix_trie(self, words):
        for i, w in enumerate(words):
            node = self.suffix_trie

            for c in w[::-1]:
                if c not in node.children:
                    node.children[c] = Trie()
                    node.children[c].c = c
                node = node.children[c]
            node.is_word = True
            node.c = w
            node.index = i

    def __init__(self, words: List[str]):
        self.prefix_trie = Trie()
        self.suffix_trie = Trie()
        self.build_prefix_trie(words)
        self.build_suffix_trie(words)

    # find all words starting with this node
    def find_all_words(self, node, res):
        if node.is_word:
            heapq.heappush(res, (-node.index, node.c))
        for c in node.children:
            self.find_all_words(node.children[c], res)

    def find(self, string, n):
        node = n
        for c in string:
            if c not in node.children:
                return -1
            node = node.children[c]
        res = []
        self.find_all_words(node, res)
        if not res:
            return -1
        else:
            return res

    def f(self, pref: str, suff: str) -> int:
        prefix_res = self.find(pref, self.prefix_trie)
        # print(idx)
        if prefix_res != -1:
            suffix_res = self.find(suff[::-1], self.suffix_trie)
            if suffix_res == -1:
                return -1
            prefix_res = sorted(prefix_res, key=lambda x: x[0])
            suffix_res = sorted(suffix_res, key=lambda x: x[0])

            for prefix_ele in prefix_res:
                if prefix_ele in suffix_res:
                    return -prefix_ele[0]
            return -1
        else:
            return -1


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)
