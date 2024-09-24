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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode*headOdd=nullptr;
        ListNode*tailOdd=nullptr;

        ListNode*headEven=nullptr;
        ListNode*tailEven=nullptr;

        int count=1;

        ListNode*temp=head;

        while(temp!=nullptr){
            if(count%2!=0){
                //Odd Index
                if(headOdd==nullptr){
                    headOdd=temp;
                    tailOdd=temp;
                }
                else{
                    tailOdd->next=temp;
                    tailOdd=tailOdd->next;
                }
                temp=temp->next;
                tailOdd->next=nullptr;
            }
            else{
                //Even Index
                if(headEven==nullptr){
                    headEven=temp;
                    tailEven=temp;
                }
                else{
                    tailEven->next=temp;
                    tailEven=tailEven->next;
                }
                temp=temp->next;
                tailEven->next=nullptr;
            }
            count++;
        }
        tailOdd->next=headEven;
        return headOdd;
    }
};