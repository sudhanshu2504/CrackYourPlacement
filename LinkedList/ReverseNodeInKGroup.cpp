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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> data;
        while(head != NULL){
            data.push_back(head->val);
            head = head->next;
        }
        ListNode* ans = NULL;
        for(int i=0 ; i<=data.size()-k ; i+=k){
            reverse(data.begin()+i,data.begin()+i+k);
        }
        for(int i=data.size()-1 ; i>=0 ; i--){
            ListNode* temp = new ListNode(data[i],ans);
            ans = temp;
        }
        return ans;
    }
};