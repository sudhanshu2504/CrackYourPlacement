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
    ListNode* partition(ListNode* head, int x) {
        vector<int> before,after;
        while(head != NULL){
            if(head->val<x){
                before.push_back(head->val);
            }else{
                after.push_back(head->val);
            }
            head = head->next;
        }
        ListNode* ans = NULL;
        for(int i=after.size()-1 ; i>=0 ; i--){
            ListNode* temp = new ListNode(after[i],ans);
            ans = temp;
        }
        for(int i=before.size()-1 ; i>=0 ; i--){
            ListNode* temp = new ListNode(before[i],ans);
            ans = temp;
        }
        return ans;
    }
};