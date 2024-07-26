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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> value;
        ListNode* ans = NULL;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                value.push_back(list1->val);
                list1 = list1->next;
            }
            else if(list2->val <= list1->val){
                value.push_back(list2->val);
                list2 = list2->next;
            }
        }
        while(list1 != NULL){
            value.push_back(list1->val);
            list1 = list1->next;
        }
        while(list2 != NULL){
            value.push_back(list2->val);
            list2 = list2->next;
        }
        for(int i=value.size()-1 ; i>=0 ; i--){
            ListNode* temp = new ListNode(value[i],ans);
            ans = temp;
        }
        return ans;
    }
};