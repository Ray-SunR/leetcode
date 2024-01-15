class Solution:
    def dfs(self, ele, lvl):
        val = 0
        if not ele.isInteger():
            for nested_ele in ele.getList():
                val += self.dfs(nested_ele, lvl - 1)
        else:
            val += ele.getInteger() * lvl
        return val

    def depth(self, nested_list, lvl):
        if nested_list.isInteger():
            return lvl
        max_lvl = lvl
        for ele in nested_list.getList():
            max_lvl = max(max_lvl, self.depth(ele, lvl + 1))
        return max_lvl
            
    """
    @param nestedList: a list of NestedInteger
    @return: the sum
    """
    def depthSumInverse(self, nestedList):
        self.ret = 0
        max_depth = 0
        for ele in nestedList:
            max_depth = max(max_depth, self.depth(ele, 1))
        
        for ele in nestedList:
            self.ret += self.dfs(ele, max_depth)
        return self.ret
