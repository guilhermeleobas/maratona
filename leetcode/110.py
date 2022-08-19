class Solution:
    def weight(self, node):
        # abs(sum(left) - sum(right)) <= 1
        if node == None:
            return 0
        left = self.weight(node.left)
        right = self.weight(node.right)
        if left < 0 or right < 0:
            return -1
        if abs(left - right) > 1:
            return -1
        return max(left, right) + 1
        
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.weight(root) >= 0
