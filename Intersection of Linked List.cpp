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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0, len2=0;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1!=NULL){
            len1++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            len2++;
            temp2 = temp2->next;
        }
        int diff = abs(len1 - len2);
        if(len1>len2){
            while(diff!=0){
                headA=headA->next;
                diff--;
            }
        }
        else{
            while(diff!=0){
                headB = headB->next;
                diff--;
            }
        }
        while(headA!=headB ){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
        
    }
};
