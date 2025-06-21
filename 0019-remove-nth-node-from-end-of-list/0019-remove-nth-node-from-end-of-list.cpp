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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next ==nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        int cnt1 = n;
        while(fast->next!=nullptr){
            fast = fast->next;
            cnt1--;
            if(!cnt1) break;
        }if(cnt1==1) return head->next;
        while(fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* newnode = slow->next;
        slow->next = newnode->next;
        delete(newnode);
        return head;
    }
};