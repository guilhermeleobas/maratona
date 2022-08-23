class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None and list2 is None:
            return None
        if list1 is not None and list2 is None:
            return list1
        if list1 is None and list2 is not None:
            return list2
        
        if list1.val < list2.val:
            val = list1.val
            p = self.mergeTwoLists(list1.next, list2)
        else:
            val = list2.val
            p = self.mergeTwoLists(list1, list2.next)
        return ListNode(val, p)
        
