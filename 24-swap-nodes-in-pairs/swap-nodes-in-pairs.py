# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def length(head):
            counter = 0
            curr = head
            while curr:
                curr = curr.next
                counter += 1
            return counter

        N = length(head)
        prevNode = None
        CurrNode = head
        ansNode = head

        k=2

        while N >= k:
            prev = None
            curr = CurrNode   # fix here

            for _ in range(k):
                nxt = curr.next
                curr.next = prev
                prev = curr
                curr = nxt

            if prevNode is not None:
                prevNode.next = prev
            else:
                ansNode = prev

            prevNode = CurrNode
            CurrNode = curr
            N -= k

        if prevNode:
            prevNode.next = CurrNode   # fix here

        return ansNode