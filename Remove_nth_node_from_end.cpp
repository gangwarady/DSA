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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 1;
        while(temp->next!=NULL){
            size++;
            temp= temp->next;
        }
        if(size == 1){
            return NULL;
        }
        temp = head;
        int node = size - n;
        if(node ==0){
            head = temp->next;
        }
        int i =0;
        while(i<node-1){
            i++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
        
        
    }
};
