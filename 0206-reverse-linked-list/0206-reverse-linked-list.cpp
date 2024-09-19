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
    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev=head;
        ListNode*n=nullptr;

        while(curr!=nullptr){
            if(curr==head){
                curr=curr->next;
                head->next=nullptr;
            }
            else{
                n=curr->next;
                curr->next=prev;
                prev=curr;
                curr=n;
            }
        }
        return prev;
    }
};