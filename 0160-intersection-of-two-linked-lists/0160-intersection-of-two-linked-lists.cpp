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
        // Start two pointers at the heads of the two lists.
        ListNode *a = headA, *b = headB;
        
        // Continue moving the pointers until they either meet or both reach the end                   //(nullptr).
        while (a != b) {
            // Move to the next node in the list, or switch to the beginning of the other list             //if at the end.
            if(a==nullptr){
                a=headB;
            }
            else{
                a=a->next;
            }
            
            if(b==nullptr){
                b=headA;
            }
            else{
                b=b->next;
            }
        }
        
        // If a and b meet, it's at the intersection node or both are nullptr (no                     //intersection).
        return a;
        
         //This meeting guarantees that the pointers have walked equal lengths, thus aligning          //their paths properly at the intersection if there is one.
    }
};