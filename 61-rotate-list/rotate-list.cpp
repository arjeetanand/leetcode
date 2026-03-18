/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findKthNode(ListNode* head, int k){
        ListNode* temp = head;
        int count=1;
        while(temp!=NULL){
            if (count == k){
                return temp;
            }
            temp = temp->next;
            count++;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k==0){
            return head;
        }
        ListNode* tail = head;
        int len = 1;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        tail->next = head;
        k= k%len;

        ListNode* lastN = findKthNode(head, len-k);
        head = lastN->next;
        lastN->next = NULL;

        return head;        
    }
};