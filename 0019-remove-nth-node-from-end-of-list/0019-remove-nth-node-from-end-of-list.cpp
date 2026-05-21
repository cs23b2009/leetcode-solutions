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
        
        int count = 0;
        ListNode* temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }

        if(count == n){
            ListNode* nodee = head;
            head = head->next;
            delete nodee;
            return head;
        }

        count -= n;

        ListNode* temp2 = head;
        ListNode* prev = nullptr;

        while(count--){
            prev = temp2;
            temp2 = temp2->next;
        }

        prev->next = temp2->next;

        delete temp2;

        return head;
    }
};