class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        num_voters = len(votes[0])
        d = {}
        for vote in votes:
            for i, team in enumerate(list(vote)):
                if team not in d:
                    d[team] = [0] * num_voters
                d[team][i] -= 1
            
        sorted_team = []
        for team in d:
            sorted_team.append([d[team], team])
        sorted_team = sorted(sorted_team)
        # print(sorted_team)
        ret = []
        for item in sorted_team:
            ret.append(item[1])
        return ''.join(ret)
