class Solution:
    def find_min_node(self, prev_node, node, min_nodes):
        if not node:
            return min_nodes
        if not min_nodes[1] or min_nodes[1].val > node.val:
            min_nodes[0] = prev_node
            min_nodes[1] = node
            min_nodes[2] = node.next 
        
        return self.find_min_node(node, node.next, min_nodes)
            
    def print(self, node):
        return
        s = ''
        while node:
            s += str(node.val)
            node = node.next
        print(s)
    def isStrictlyDecresing(self, head):
        decreasing = True
        prev = None
        while head:
            if prev and head.val > prev.val:
                return False
            prev = head
            head = head.next
        return False
    def reverse(self, head):
        prev = None
        node = head
        while node:
            n = node.next
            node.next = prev
            prev = node
            node = n
        return prev
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev_node = None
        node = head
        if self.isStrictlyDecresing(head):
            print(True)
            return self.reverse(head)
        while node:
            # print(node.val)
            prev_min_node, min_node, next_min_node = self.find_min_node(prev_node, node, [None, None, None])
            # swap current node with min_node found
            if min_node:
                # print('prev_node: {}, min_node: {}, next_node: {}'.format(prev_min_node.val if prev_min_node else 'None', min_node.val, next_min_node.val if next_min_node else 'None'))
                tmp = min_node.val
                min_node.val = node.val
                node.val = tmp
            node = node.next
        return head
