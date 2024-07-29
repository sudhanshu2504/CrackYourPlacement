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
        vector<int> n1;
        vector<int> n2;

        while(l1 != nullptr){
            n1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr){
            n2.push_back(l2->val);
            l2 = l2->next;
        }
        reverse(n1.begin(),n1.end());
        reverse(n2.begin(),n2.end());
        int i=0;
        vector<int> result;
        int carry = 0;
        while(i<n1.size() && i<n2.size()){
            int a = n1[i]+n2[i];
            if(carry == 1){
                a++;
                carry = 0;
            }
            if(a>9){
                carry = 1;
            }
            result.push_back(a%10);
            if((i == n1.size()-1 && i == n2.size()-1) && carry == 1){
                result.push_back(1);
                carry = 0;
            }
            i++;
        }
        while(i<n1.size()){
            if(carry == 1){
                n1[i]++;
                carry = 0;
            }
            if(n1[i]>9){
                carry = 1;
            }
            result.push_back(n1[i]%10);
            if(i == n1.size()-1 && carry == 1){
                result.push_back(1);
                carry = 0;
            }
            i++;
        }
        while(i<n2.size()){
            if(carry == 1){
                n2[i]++;
                carry = 0;
            }
            if(n2[i]>9){
                carry = 1;
            }
            result.push_back(n2[i]%10);
            if(i == n2.size()-1 && carry == 1){
                result.push_back(1);
                carry = 0;
            }
            i++;
        }
        
        ListNode* ans = nullptr;
        for(int j=0 ; j<result.size() ; j++){
            ListNode* node = new ListNode(result[j],ans);
            ans = node;
        }
        return ans;
    }
};