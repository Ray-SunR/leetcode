ass FileSystem:
    def __init__(self):
        self.d = {}

    def find(self, path):
        node = self
        for p in path:
            if p not in node.d:
                return None

            node = node.d[p]
        
        return node
        
    """
    @param path: the path to be created
    @param val: path associated value
    @return: the result of create
    """
    def create_path(self, path: str, val: int) -> bool:
        names = path.split('/')
        names = names[1:]
        if len(names) == 1:
            node = self.find([names[0]])
            if not node:
                self.d[names[0]] = FileSystem()
                self.d[names[0]].val = val
                return True
            else:
                return False
        found = self.find(names[:-1])
        if not found or names[-1] in found.d:
            return False
        found.d[names[-1]] = FileSystem()
        found.d[names[-1]].val = val
        return True
        

    """
    @param path: the path of retrieve
    @return: path associated value
    """
    def get(self, path: str) -> int:
        names = path.split('/')[1:]
        found = self.find(names)
        if not found:
            return -1

        return found.val
