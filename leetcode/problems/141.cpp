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
    set<ListNode*> st;
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }

        while(head->next){
            st.insert(head);

            if(st.find(head->next) != st.end()){
                return true;
            }
            head = head->next;
        }
        
        return false;
    }
};