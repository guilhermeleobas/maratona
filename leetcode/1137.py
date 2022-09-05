class Solution:
    def tribonacci(self, n: int) -> int:
        r = [0] * (38)
        r[1] = 1
        r[2] = 1
        for i in range(3, n+1):
            r[i] = r[i-1] + r[i-2] + r[i-3]
        return r[n]
