class Solution:

    def candy(self, ratings: List[int]) -> int:
        candies = [1] * len(ratings)
        for i in range(len(ratings)):
            if i - 1 >= 0 and ratings[i] > ratings[i - 1] and candies[i] <= candies[i - 1]:
                candies[i] = candies[i - 1] + 1
        for i in range(len(ratings) - 1, -1, -1):
            if i + 1 < len(ratings) and ratings[i] > ratings[i + 1] and candies[i] <= candies[i + 1]:
                candies[i] = candies[i + 1] + 1
        # print(candies)
        return sum(candies)
