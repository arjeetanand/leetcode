class Solution {
public:
    int getDecimalValue(ListNode* head) {
       string s="";
       ListNode* temp=head;
       while(temp!=NULL){
        s+=to_string(temp->val);
        temp=temp->next;
       }
       int ans=0;
       int n=s.size();
       for(int i=0;i<n;i++){
        int bit = s[i] - '0'; 
        ans += (bit * (1 << (n - i - 1))); 
       }
       return ans;
    }
};