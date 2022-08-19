class Solution:
    def solve(self, node):
        if node is None:
            return None
        if node.val == 1:
            return TreeNode(1, self.solve(node.left), self.solve(node.right))

        left = self.solve(node.left)
        right = self.solve(node.right)
        if left or right:
            return TreeNode(node.val, left, right)
        else:
            return None

    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.solve(root)
