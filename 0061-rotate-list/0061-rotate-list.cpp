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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0 || head->next==nullptr ) return head;
        ListNode* temp = head;
        int leng=0;
        while(temp!=nullptr){
            temp=temp->next;
            leng++;
        }
        if(k % leng == 0) return head;
        int cnt1 = k%leng ;
        cnt1 = leng - cnt1;
        ListNode* prev = nullptr;
        temp = head;
        while(cnt1!=0){
            ListNode* newnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newnode;
            cnt1--;
        }
        if(temp->next==nullptr) {
            head->next = temp;
            temp = prev;
            prev = nullptr;
        while(temp!=nullptr){
            ListNode* newnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newnode;
        }
        return prev;
        }
        else{
            ListNode* prev1 = nullptr;
            while(temp!=nullptr){
            ListNode* newnode2 = temp->next;
            temp->next = prev1;
            prev1 = temp;
            temp = newnode2;
            }
            head->next = prev1;
        }
        temp = prev;
        prev = nullptr;
        while(temp!=nullptr){
            ListNode* newnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newnode;
        }
        return prev;

    }
};