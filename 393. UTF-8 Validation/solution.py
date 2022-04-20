class Solution:
    def isvalid(self, data, start, size):
        for i in range(start, start + size):
            if i >= len(data) or data[i] >> 6 != 0b10:
                return False
        return True
    def validUtf8(self, data: List[int]) -> bool:
        if not data:
            return True
        i = 0
        while i < len(data):
            if data[i] >> 7 == 0:
                if not self.isvalid(data, i + 1, 0):
                    return False
                i += 1
            elif data[i] >> 5 == 0b110:
                if not self.isvalid(data, i + 1, 1):
                    return False
                i += 2
            elif data[i] >> 4 == 0b1110:
                if not self.isvalid(data, i + 1, 2):
                    return False
                i += 3
            elif data[i] >> 3 == 0b11110:
                if not self.isvalid(data, i + 1, 3):
                    return False
                i += 4
            else:
                return False
        return True
