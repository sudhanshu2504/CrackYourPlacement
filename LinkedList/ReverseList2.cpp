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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    vector<int> value;
    while(head != nullptr){
        value.push_back(head->val);
        head = head->next;
    }
    reverse(value.begin()+left-1, value.begin()+right);
    ListNode* ans = nullptr;
    for(int i=value.size()-1 ; i>=0 ; i--){
        ListNode* node = new ListNode(value[i],ans);
        ans = node;
    }
    return ans;
    }
};