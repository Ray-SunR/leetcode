class Trie:
    def __init__(self, c=""):
        self.c = c
        self.children = {}
        self.is_word = False
        self.word = None


class Solution:
    def build_trie(self, products):
        self.root = Trie()
        for product in products:
            node = self.root
            for c in product:
                if c not in node.children:
                    node.children[c] = Trie(c)
                node = node.children[c]
            node.is_word = True
            node.word = product

    # find all words under node
    def find_all_words(self, node, res):
        if not node:
            return
        # print(node.c)
        if node.is_word:
            res.append(node.word)
        for c in node.children:
            n = node.children[c]
            self.find_all_words(n, res)

    def find_words(self, searchWord):
        node = self.root
        ret = []
        for c in searchWord:
            res = []
            # print('c: {}, node: {}'.format(c, node.c))
            if node:
                node = node.children.get(c, None)
                self.find_all_words(node, res)
            ret.append(sorted(res)[:3])
        return ret

    def suggestedProducts(
        self, products: List[str], searchWord: str
    ) -> List[List[str]]:
        self.build_trie(products)

        return self.find_words(searchWord)
