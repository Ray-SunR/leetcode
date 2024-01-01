class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        d = {}
        for age in ages:
            if age not in d:
                d[age] = 0
            d[age] += 1
        counter = 0
        for me_age in d:
            for you_age in d:
                if me_age == you_age:
                    continue
                if not (you_age <= 0.5 * me_age + 7 or you_age > me_age or (you_age > 100 and me_age < 100)):
                    # print('me_age: {} to you_age: {}'.format(me_age, you_age))
                    counter += d[me_age] * d[you_age]
                
            if not me_age <= 0.5 * me_age + 7:
                counter += d[me_age] * (d[me_age] - 1)
        
        return counter
            
