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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a,b;
        while(l1 != NULL){
            a.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            b.push_back(l2->val);
            l2 = l2->next;
        }
        vector<int> ans;
        int carry = 0;
        int i=0;
        while(i<a.size() && i<b.size()){
            int temp = a[i]+b[i]+carry;
            carry = 0;
            if(temp>9){
                carry = 1;
                temp = temp%10;
            }
            ans.push_back(temp);
            i++;
        }
        while(i<a.size()){
            int temp = a[i] + carry;
            carry = 0;
            if(temp>9){
                carry = 1;
                temp = temp%10;
            }
            ans.push_back(temp);
            i++;
        }
        while(i<b.size()){
            int temp = b[i] + carry;
            carry = 0;
            if(temp>9){
                carry = 1;
                temp = temp%10;
            }
            ans.push_back(temp);
            i++;
        }
        if(carry){
            ans.push_back(1);
        }
        ListNode* result = NULL;
        for(int i=ans.size()-1 ; i>=0 ; i--){
            ListNode* temp = new ListNode(ans[i],result);
            result = temp;
        }
        return result;
    }
};