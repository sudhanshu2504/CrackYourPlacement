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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = NULL;
        vector<int> value;
        while(head != NULL){
            if(head->val != val){
                value.push_back(head->val);
            }
            head = head->next;
        }
        for(int i=value.size()-1 ; i>=0 ; i--){
            ListNode* temp = new ListNode(value[i],ans);
            ans =  temp;
        }
        return ans;
    }
};