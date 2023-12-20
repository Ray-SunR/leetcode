class TopVotedCandidate:
    def __init__(self, persons: List[int], times: List[int]):
        self.leaders = []
        self.times = times
        max_vote = 0
        current_leader = -1
        d = {}
        for person in persons:
            d[person] = d.get(person, 0) + 1
            if d[person] >= max_vote:
                current_leader = person
                max_vote = d[person]
            self.leaders.append(current_leader)
        print(self.leaders)

    def q(self, t: int) -> int:
        idx = bisect.bisect(self.times, t)
        # print('time: {}, idx: {}'.format(t, idx))
        return self.leaders[idx - 1] if idx >= 1 else self.leaders[idx]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
