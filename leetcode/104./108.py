class Solution:
    def solve(self, nums, a, b):
        if a > b:
            return None
        
        mid = (b + a) // 2
        val = nums[mid]
        left = self.solve(nums, a, mid-1)
        right = self.solve(nums, mid+1, b)
        return TreeNode(val, left, right)

    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.solve(nums, 0, len(nums)-1)
