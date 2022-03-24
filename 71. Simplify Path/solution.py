class Solution:
    def simplifyPath(self, path: str) -> str:
        splitted = path.split('/')
        elements = []
        for s in splitted:
            if not s:
                continue
            if s == '..':
                if len(elements) > 0:
                    elements.pop()
            elif s != '.':
                elements.append(s)

        ret = '/'.join(elements)

        if ret and ret[-1] == '/':
            ret = ret[:-1]

        ret = '/' + ret
        return ret
                
