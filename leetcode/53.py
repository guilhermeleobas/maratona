class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        m = nums[0]
        s = nums[0]
        for i in range(1, len(nums)):
            if nums[i] + m < nums[i]:
                m = nums[i]
            else:
                m += nums[i]
            s = max(s, m)
        return s
