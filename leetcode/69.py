class Solution:
    def mySqrt(self, x: int) -> int:
        if x in [0, 1]:
            return x
        left, right = 0, x
        while left < right:
            mid = (left + right) // 2
            r = mid * mid
            if left + 1 == right:
                # ans is either left or right
                t = right * right
                if t - x <= 0:
                    return right
                else:
                    return left
            if r <= x:
                left = mid
            else:
                right = mid-1
        return left
