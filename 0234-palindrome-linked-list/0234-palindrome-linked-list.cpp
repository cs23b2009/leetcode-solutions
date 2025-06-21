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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr!=nullptr && fastptr->next!=nullptr){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slowptr;
        while(curr!=nullptr){
            ListNode* newnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newnode;
        }
        while(prev&&head){
            if(prev->val != head->val){
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};