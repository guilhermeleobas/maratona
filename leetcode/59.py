class Solution:
    def fill(self, matrix, N, begin, val):
        # left-right
        # [begin, N-begin)
        for j in range(begin, N-begin):
            matrix[begin][j] = val
            val += 1
        # up-down
        # [begin, N-begin)
        val -= 1
        for i in range(begin, N-begin):
            matrix[i][N-1-begin] = val
            val += 1
        # right-left
        val -= 1
        for j in range(N-1-begin, begin-1, -1):
            matrix[N-1-begin][j] = val
            val += 1
        # down-up
        val -= 1
        for i in range(N-1-begin, begin, -1):
            matrix[i][begin] = val
            val += 1
        return val

    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 1:
            return [[1]]
        val = 1
        matrix = [[0] * n for _ in range(n)]
        for begin in range(n-1):
            val = self.fill(matrix, n, begin, val)
        return matrix
