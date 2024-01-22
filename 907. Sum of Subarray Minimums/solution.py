class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        answer = 0
        left = [-1] * n
        right = [n] * n
        left_stk = []
        right_stk = []
        # left
        for i in range(n):
            # find the nearest number's index to the left of i that is smaller than arr[i]
            while left_stk and arr[left_stk[-1]] >= arr[i]:
                left_stk.pop(-1)
            if left_stk:
                left[i] = left_stk[-1]
            left_stk.append(i)

        i = n - 1
        while i >= 0:
            # find the nearest number's index to the left of i that is smaller than arr[i]
            while right_stk and arr[right_stk[-1]] > arr[i]:
                right_stk.pop(-1)
            if right_stk:
                right[i] = right_stk[-1]
            right_stk.append(i)
            i -= 1

        # print('left_stk: {}, right_stk: {}'.format(left, right))

        for i in range(n):
            answer += arr[i] * (i - left[i]) * (right[i] - i)
            answer %= 10**9 + 7
        return answer
