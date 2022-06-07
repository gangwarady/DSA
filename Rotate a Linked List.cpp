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
    ListNode* rotateRight(ListNode* head, int k) {
       
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *temp = head;
        int len = 0;
        while(temp!=NULL){
            temp= temp->next;
            len++;
        }
        k=k%len;
        //cout<<k;
        while(k>0){
            k--;
            int count = 1;
            ListNode *nex = head->next;
            ListNode *prev = head;
            while(count!=(len-1)){
                nex = nex->next;
                prev = prev->next;
                count++;
            }
            nex->next = head;
            head = nex;
            prev->next = NULL;
        }
        return head;
    }
};
