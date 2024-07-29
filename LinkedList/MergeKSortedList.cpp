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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> value;
        for(int i=0 ; i<lists.size() ; i++){
            while(lists[i]){
                value.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(value.begin(),value.end());

        ListNode* ans = NULL;
        for(int i=value.size()-1 ; i>=0 ; i--){
            ListNode* node = new ListNode(value[i],ans);
            ans = node;
        }
        return ans;
    }
};