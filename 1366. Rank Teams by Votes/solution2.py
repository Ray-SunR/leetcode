class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        if not votes:
            return ""
        # {'A': [5, 0, 0], 'B': [0, 2, 3], 'C': [0, 3, 2]}
        d = {}
        for vote in votes:
            chars = list(vote)
            for i, char in enumerate(chars):
                if char not in d:
                    d[char] = [0] * len(votes[0])
                d[char][i] -= 1
        print(d)
        data = sorted([(d[char], char) for char in d])
        ret = ''.join([item[1] for item in data])
        return ret
