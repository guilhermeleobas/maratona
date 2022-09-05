class Solution:
    def format_output(self, nums, l, r):
        if l == r:
            return f'{nums[l]}'
        else:
            return f'{nums[l]}->{nums[r]}'

    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0:
            return []
        l, r = 0, 0
        i = 1
        ans = []
        while i < len(nums):
            if nums[i] == nums[i-1] + 1:
                r = i
            else:
                ans.append(self.format_output(nums, l, r))
                l, r = i, i
            i += 1
        ans.append(self.format_output(nums, l, r))
        return ans
