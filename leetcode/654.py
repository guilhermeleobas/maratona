class Solution:
    def build(self, nums, a, b):
        if a >= b:
            return None
        m = max(nums[a:b])
        idx = nums[a:b].index(m) + a
        left = self.build(nums, a, idx)
        right = self.build(nums, idx+1, b)
        return TreeNode(m, left, right)

    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        return self.build(nums, 0, len(nums))
