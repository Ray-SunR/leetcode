

def max_breadth(s):
    stk = []
    hmap = {}
    lvl = 0
    ret = 0
    for c in s:
        if c == '(':
            stk.append(c)
            if lvl not in hmap:
                hmap[lvl] = 0
            hmap[lvl] += 1
            ret = max(hmap[lvl], ret)
            lvl += 1
        elif c == ')':
            stk.pop(-1)
            lvl -= 1
    return ret

def max_depth(s):
    stk = []
    ret = 0
    for c in s:
        if c == '(':
            stk.append(c)
            ret = max(ret, len(stk))
        elif c == ')':
            stk.pop(-1)
    return ret

assert max_breadth('((()()()))') == 3
assert max_breadth('()') == 1
assert max_breadth('()()()()') == 4
assert max_breadth('((())()())()()(())(((())))') == 5

assert max_depth('((((()))))') == 5
assert max_depth('()()()()') == 1

