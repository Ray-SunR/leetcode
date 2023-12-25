class Solution:
    def pathInZigZagTree(self, label: int) -> list:
           # Calculate the level of the node
        level = int(math.log2(label)) + 1
        path = []

        while label != 1:
            path.insert(0, label)
            # Adjust for the zigzag pattern by finding the label's mirrored position on the level
            high = 2**level
            low = 2**(level - 1)
            label = (low + (high - label) - 1) // 2
            # label //= 2  # Move to the parent label
            level -= 1  # Move up a level

        path.insert(0, 1)  # Adding the root at the beginning
        return path

