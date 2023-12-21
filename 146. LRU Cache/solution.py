ass Node:
    def __init__(self, key, value, next=None):
        self.key = key
        self.value = value
        self.pre = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        # map between key and Node
        self.d = {}
        # actual data which is a linked list of Node
        self.data = None
        self.tail = None
        self.size = capacity

    def get(self, key: int) -> int:
        if key not in self.d:
            return -1
        self.move_node_to_front(key)
        self.p()
        return self.data.value

    def move_node_to_front(self, key):
        # found the data
        node = self.d[key]
        
        if node == self.data:
            return
        
        # need to move the node to front
        node_pre = node.pre
        node_next = node.next
        
        # A <-> B <-> C
        # becomes
        # A <-> C
        node_pre.next = node_next
        if node_next:
            node_next.pre = node_pre
        else:
            # means this is a tail node, we need to update the tail
            self.tail = node_pre
        
        node.next = self.data
        node.pre = None
        
        self.data.pre = node
        
        self.data = node
    
    def put(self, key: int, value: int) -> None:
        if not self.data:
            self.data = Node(key, value)
            self.tail = self.data
            self.d[key] = self.data
        elif key in self.d:
            # move that Node to front and update its value
            self.move_node_to_front(key)
            self.data.value = value
        elif len(self.d) == self.size:
            # need to evict the last item from the list
            tail_pre = self.tail.pre
            tail_key = self.tail.key
            self.tail = tail_pre
            if self.tail:
                self.tail.next = None
            del self.d[tail_key]
            # insert that item to the front
            new_node = Node(key, value)
            new_node.next = self.data
            self.data.pre = new_node
            self.data = new_node
            self.d[key] = new_node
            
            if not self.tail:
                self.tail = new_node
        else:
            # insert that item to the front
            new_node = Node(key, value)
            new_node.next = self.data
            self.data.pre = new_node
            self.data = new_node
            self.d[key] = new_node
        self.p()
        
    def p(self):
        return
        temp = self.data
        s = ""
        while temp:
            s += ", (" + str(temp.key) + ", " + str(temp.value) + ")"
            temp = temp.next
        
        print(s + ", tail: " + str(self.tail.value))

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
