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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        unordered_map<ListNode*, int> mpp;  // ✅ Use pointer type
        while(temp1 != nullptr){
            mpp[temp1] = 1;
            temp1 = temp1->next;
        }
        ListNode* temp2 = headB;
        while(temp2 != nullptr){
            if(mpp.find(temp2) != mpp.end())
                return temp2;
            temp2 = temp2->next;
        }
        return nullptr;
    }
};