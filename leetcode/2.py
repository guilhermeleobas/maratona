
class Solution:
    def solve(self, l1, l2, carry):
        if l1 and l2:
            val = (l1.val + l2.val + carry)
            val, carry = (val % 10), (val // 10)
            prox = self.solve(l1.next, l2.next, carry)
        elif l1:
            val = l1.val + carry
            val, carry = (val % 10), (val // 10)
            prox = self.solve(l1.next, None, carry)
        elif l2:
            val = l2.val + carry
            val, carry = (val % 10), (val // 10)
            prox = self.solve(None, l2.next, carry)
        else:
            if carry:
                return ListNode(carry, None)
            return None

        return ListNode(val, prox)


    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        return self.solve(l1, l2, 0)
