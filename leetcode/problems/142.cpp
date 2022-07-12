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
    map<ListNode*, int> mp;
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        
        int cnt = 0;
        while(head->next){
            mp[head] = cnt;
            
            if(mp.count(head->next)){
                return head->next;
            }
            
            head = head->next;
            cnt++;
        }
        
        return NULL;
    }
};