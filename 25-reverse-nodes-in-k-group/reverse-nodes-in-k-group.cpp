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
    ListNode* findK(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k> 0){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* temp){
            ListNode* prev = NULL;
            while(temp){
                ListNode * nextNode = temp -> next;
                temp -> next = prev;
                prev= temp;
                temp = nextNode;
            }
            return  prev;
        }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* previous = NULL;
        while(temp){
            ListNode* kth = findK(temp, k);
            if(kth == NULL){
                if (previous) previous -> next = temp;
                break;
            }
            ListNode* nextG = kth->next;
            kth->next = NULL;
            ListNode* headnext = reverse(temp);
            if(head == temp){
                head = kth;
            }else{
                previous -> next = headnext;
            }
            previous = temp;
            temp = nextG;
        }
        return head;        
    }
};