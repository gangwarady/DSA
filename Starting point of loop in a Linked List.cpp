/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        int flag =0;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                flag =1;
                break;
            }
        }
        if(flag){
            int pos = 0;
            ListNode* dummy = head;
            while(dummy!=slow){
                slow = slow->next;
                dummy = dummy->next;
                pos++;
            }
            return dummy;
        }
        else{
            return NULL;
        }
        
    }
};
