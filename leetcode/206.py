# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def apply(self, prev, curr):
        if curr is None:
            return prev
        next_ = curr.next
        curr.next = prev
        return self.apply(curr, next_)

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.apply(None, head)
