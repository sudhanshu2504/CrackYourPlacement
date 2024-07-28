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
    void reorderList(ListNode* head) {
    vector<int> value;
    ListNode* temp = head;
    while(temp != nullptr){
        value.push_back(temp->val);
        temp = temp->next;
    }
    temp = head;
        int i=0, j=value.size()-1;
        while(i<j){
            temp->val = value[i++];
            temp = temp->next;
            temp->val = value[j--];
            temp = temp->next;
        }
        if(i == j){
            temp->val = value[i++];
        }
        return;
    }
};