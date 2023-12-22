class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        self.votes = {}
        self.times = times
        self.result = []
        max_vote_person = 0
        for person in persons:
            if person not in self.votes:
                self.votes[person] = 0
            self.votes[person] += 1
            if self.votes[person] >= self.votes.get(max_vote_person, 0):
                max_vote_person = person
            self.result.append(max_vote_person)
        # print(self.votes)
        # print(self.result)

    def q(self, t: int) -> int:
        idx = bisect.bisect(self.times, t)
        # print(idx)
        return self.result[idx -1]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
