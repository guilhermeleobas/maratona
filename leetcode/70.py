# 1 -> (1)
# 2 -> (1, 1), (2)
# 3 -> (1, 2), (2, 1), (1, 1, 1)
# 4 -> (1, 2, 1), (2, 1, 1), (1, 1, 1, 1), (1, 1, 2), (2, 2)
# 5 -> ()

class Solution:
    def climbStairs(self, n: int) -> int:
        R = [0] * 46
        R[1] = 1
        R[2] = 2
        R[3] = 3
        for i in range(3, n+1):
            R[i] = R[i-1] + R[i-2]
        return R[n]
