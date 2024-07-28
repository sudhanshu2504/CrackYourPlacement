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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;

        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> freq;
        while(head != NULL){
            freq[head->val]++;
            head = head->next;
        }
        ListNode* ans = NULL;
        for(auto &i:freq){
            if(i.second == 1){
                ListNode* temp = new ListNode(i.first,ans);
                ans = temp;
            }
        }
        return reverse(ans);
    }
};