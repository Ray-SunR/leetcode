class FileSystem:
    def __init__(self):
        self.val = None
        self.children = {}

    def find(self, splitted_paths):
        node = self
        for path in splitted_paths:
            if path in node.children:
                node = node.children[path]
            else:
                return None
        return node

    """
    @param path: the path to be created
    @param val: path associated value
    @return: the result of create
    """
    def create_path(self, path: str, val: int) -> bool:
        splitted = path.split('/')[1:]
        print(splitted)
        parent_node = self.find(splitted[:-1])
        if parent_node and splitted[-1] not in parent_node.children:
            new_node = FileSystem()
            new_node.val = val
            parent_node.children[splitted[-1]] = new_node
            return True
        else:
            return False

    """
    @param path: the path of retrieve
    @return: path associated value
    """
    def get(self, path: str) -> int:
        node = self.find(path.split('/')[1:])
        return node.val if node else -1
