#include <bits/stdc++.h>
using namespace std;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *res = new ListNode(0), *current = res;
        
        int carry = 0;
        while(l1 || l2){
            int one, two;
            if(l1){
                one = l1->val;
            }else{
                one = 0;
            }
            if(l2){
                two = l2->val;
            }else{
                two = 0;
            }
            int sum = one + two + carry;
            carry = sum / 10;
            int num = sum % 10;
            current->next = new ListNode(num);
            current = current->next;
            
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        
        if(carry){
            current->next = new ListNode(carry);
            current = current->next;
        }
        
        return res->next;
        
    }
};