from typing import (
    List,
)

class Solution:
    """
    @param heights: An integer array
    @return: Indexs of buildings with sea view
    """
    def find_buildings(self, heights: List[int]) -> List[int]:
        stk = []
        for i, height in enumerate(heights):
            while stk and heights[stk[-1]] <= height: 
                # all buildings in the stk that are lower than the current building
                # do not have an ocean view
                stk.pop()
            stk.append(i)
        return stk

