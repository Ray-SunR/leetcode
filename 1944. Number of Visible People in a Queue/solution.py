class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        # stk is used to keep track of indecies that are higher than the current element
        # meaning that if we encounter a person whose height is greater than the top of the stk, then it means all elements in the stk won't be visible anymore, but all elements within the stk can see the current tall element
        # if the stk is not empty, meaning that there is an element in the stk that is higher than current height and that element in the stk can see the current element so we increase count by one for that element in the stk
        stk = []
        ret = [0] * len(heights)
        for i, height in enumerate(heights):
            while stk and heights[stk[-1]] < height:
                ret[stk.pop()] += 1
            if stk:
                ret[stk[-1]] += 1
            stk.append(i)
        return ret
        
