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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp != nullptr){
            if(mpp.find(temp) == mpp.end()){
                mpp[temp] = 1;
            }
            else{
                return temp; // Cycle detected here
            }
            temp = temp->next;
        }
        return nullptr; // No cycle found
    }
};