class TopVotedCandidate:
    def __init__(self, persons: List[int], times: List[int]):
        self.leaders = [0] * len(persons)
        self.votes = {}
        max_vote_count = 0
        max_leader = 0
        self.times = times
        for i, team_id in enumerate(persons):
            if team_id not in self.votes:
                self.votes[team_id] = 0
            self.votes[team_id] += 1
            if self.votes[team_id] >= max_vote_count:
                self.leaders[i] = team_id
                max_leader = team_id
                max_vote_count = self.votes[team_id]
            else:
                self.leaders[i] = max_leader
        # print(self.leaders)

    def q(self, t: int) -> int:
        idx = bisect.bisect_right(self.times, t) - 1
        # print(idx)
        return self.leaders[idx]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
