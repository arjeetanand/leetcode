# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        minheap = []
        for node in lists:
            while node:
                minheap.append(node.val)
                node=node.next
        heapq.heapify(minheap)

        dummy=  start= ListNode(None)
        while minheap:
            start.next = ListNode(heapq.heappop(minheap))
            start= start.next
        
        return dummy.next


