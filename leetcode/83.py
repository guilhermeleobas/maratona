# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def apply(self, prev, curr):
        if curr is None:
            prev.next = None
            return
        if prev.val == curr.val:
            self.apply(prev, curr.next)
        else:
            prev.next = curr
            self.apply(curr, curr.next)
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return
        self.apply(head, head.next)
        return head
