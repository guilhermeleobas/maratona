class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        s = sum(nums)
        N = len(nums)
        exp_sum = (N*(N+1)) // 2
        
        if exp_sum < s:
            return N  # missing the last element
        elif exp_sum == s:
            return 0  # missing 0
        else:  # exp_sum > s
            return exp_sum - s
        
