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
        // Get lengths of both lists
        int length1 = 0, length2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1 != nullptr){
            length1++;
            temp1 = temp1->next;
        }
        
        while(temp2 != nullptr){
            length2++;
            temp2 = temp2->next;
        }
        
        // Reset pointers
        temp1 = headA;
        temp2 = headB;
        
        // Move the pointer of longer list forward by difference in lengths
        int d = abs(length1 - length2);
        if(length1 > length2){
            while(d--) temp1 = temp1->next;
        } else {
            while(d--) temp2 = temp2->next;
        }
        
        // Move both pointers together until intersection is found
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return nullptr;
    }
};