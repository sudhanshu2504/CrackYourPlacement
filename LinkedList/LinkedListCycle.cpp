/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode* , int> maps;
        
        while (head != nullptr){
            maps[head]++;
            if(maps[head] > 1){
                return true;
            }
            head = head->next;
        }
        return false;
    }
};