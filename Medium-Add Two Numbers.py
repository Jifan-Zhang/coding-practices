# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sum=0;multiplier=1
        while(l1 and l2):
            sum+=(l1.val+l2.val)*multiplier
            multiplier*=10
            l1=l1.next
            l2=l2.next
        
        l=l1 if l2 is None else l2

        while(l is not None):
            sum+=l.val*multiplier
            multiplier*=10
            l=l.next
            
        link=ListNode(0)
        prev=link
        while(sum>=10):
            lk=ListNode(sum%10)
            prev.next=lk
            prev=lk
            sum//=10
        prev.next=ListNode(sum)
        return link.next
