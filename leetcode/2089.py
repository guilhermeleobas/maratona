class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        le, gt = 0, 0
        for e in nums:
            if e < target:
                le += 1
            elif e > target:
                gt += 1
                
        # array is [..le.., targets, ..gt..]
        N = len(nums)
        N_targets = N - le - gt
        gt = le + N_targets
        return list(range(le, gt))
