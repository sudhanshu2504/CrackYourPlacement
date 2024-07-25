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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> value;
        while(head != NULL){
            value.insert(head->val);
            head = head->next;
        }
        ListNode* ans = NULL;
        for(auto &i:value){
            ListNode* temp = new ListNode(i,ans);
            ans =  temp;
        }
        return reverse(ans);
    }
};