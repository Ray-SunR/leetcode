class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        if not votes:
            return ""
        # key is the team, value is a list keeping track of vote count, the index in the list is the position.
        d = {}
        num_teams = len(votes[0])
        for item in votes:
            for i, c in enumerate(item):
                val = d.get(c, [0] * num_teams)
                val[i] = val[i] + 1
                d[c] = val
        ret = []
        # print(d)
        # sort based on the list first then by the team's alphabet name
        # note that ora('A') - ord(item[0]) means we need to sort in reverse order of alphabets
        ordered = sorted(d.items(), key=lambda item: (item[1], ord('A') - ord(item[0])))
        # the ordered result here is the result in reverse order. 
        # print(ordered)
        for item in ordered:
            ret.insert(0, item[0])
        return "".join(ret)
