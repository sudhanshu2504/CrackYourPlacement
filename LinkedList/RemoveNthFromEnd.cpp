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
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        int posi = count - n ;
        if(count == 1 && n==1){
            return nullptr;
        }
        if(posi == 0){
            temp = head;
            return head->next;
        }else{
        ListNode* temp2 = head;
        for(int i=1 ; i<=posi ; i++){
            if(i == posi){
                temp2->next = temp2->next->next;
                break;
            }else{
                temp2 = temp2->next;
            }
        }
        }
        return head ;
    }
};