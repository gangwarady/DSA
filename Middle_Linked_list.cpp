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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 1;
        while(temp->next!=NULL){
            temp = temp->next;
            count++;
        }
        int middle = 0;
        if(count%2){
            middle = ((count+1)/2);
        }
        else{
            middle = ((count+2)/2);
        }
        //cout<<middle;
        temp = head;
        count = 1;
        while(count!=middle){
            temp= temp->next;
            count++;
        }
        return temp;
    }
};
