# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        def len(head, k):
            counter= 0
            curr=head
            while(curr):
                curr= curr.next
                counter+=1
            return counter
        N= len(head, k)
        currhead=head
        prevhead=None
        ans=head
        while(N>=k):            
            curr=currhead
            prev=None

            for _ in range(k):
                nxt= curr.next
                curr.next= prev
                prev= curr
                curr=nxt
            
            if prevhead is not None:
                prevhead.next=prev
            else:
                ans=prev
            prevhead=currhead
            currhead=curr
            N=N-k

        if prevhead: 
            prevhead.next = currhead
        return ans