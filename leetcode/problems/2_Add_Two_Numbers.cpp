#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        vector<int> list_1;
        vector<int> list_2;
        
        ListNode* current_1 = l1;
        ListNode* current_2 = l2;
        while(current_1 != NULL){
            list_1.push_back(current_1 -> val);
            current_1 = current_1 -> next;
        }
        while(current_2 != NULL){
            list_2.push_back(current_2 -> val);
            current_2 = current_2 -> next;
        }
        
        int ans = 0;
        for(int i = 0; i < list_1.size(); i++){
            ans += list_1[list_1.size() - 1 - i] * pow(10, i);
        }
        for(int i = 0; i < list_2.size(); i++){
            ans += list_2[list_2.size() - 1 - i] * pow(10, i);
        }
        
        cout << ans << endl;
        
        string ans_s = to_string(ans);
        
        ListNode* res;
        
        
        
        cout << "---" << endl;
        cout << l1 -> val << endl;
        cout << l1 -> next << endl;
        cout << l1 -> next -> val << endl;
        cout << l1 -> next -> next -> val << endl;
        cout << l1 -> next -> next -> next << endl;
        if(l1 -> next -> next -> next == NULL){
            cout << "ok" << endl;
        }
        cout << l1 -> next -> next -> next << endl;
        return l1;
    }
};

int main(){
    ListNode* tmp_l1 = new ListNode(2);//2,4,3
    ListNode* tmp_l2 = new ListNode(5);//5,6,4

    ListNode* l1 = tmp_l1;
    ListNode* l2 = tmp_l2;

    tmp_l1 = tmp_l1.next;
    tmp_l2 = tmp_l2.next;

    cout << tmp_l1->val << endl;
    cout << tmp_l2->val << endl;
    cout << l1->val << endl;
    cout << l2->val << endl;
    //Solution.addTwoNumbers(l1, l2);
}