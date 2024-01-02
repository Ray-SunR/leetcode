class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        data = []
        stk = []
        ret = [0] * n
        for log in logs:
            splitted = log.split(':')
            fid = int(splitted[0])
            start_end = splitted[1]
            time = int(splitted[2])
            if start_end == 'start':
                if stk:
                    ret[stk[-1][0]] = ret[stk[-1][0]] + (time - stk[-1][1])
                stk.append([fid, time])
            else:
                top = stk.pop()
                duration = time - top[1] + 1
                ret[fid] += duration
                if stk:
                    stk[-1][1] = time + 1
        return ret
        
        # ["0:start:0","1:start:2","1:end:5","0:end:6"] -> [(0, 6, 0), (2, 5, 1)]
        # ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"] -> [(0, 7, 0), (2, 5, 0), (6, 6, 0)] -> [0, 2, 5, 6, 7] -> 2 + 3 + 1 + 1 + 1 = 8
        # stk_sum = 4, ret[0] = 4
        # stk_sum = 1, ret[0] = 5
        # 7 - 0 - 1 + 1 = 7
