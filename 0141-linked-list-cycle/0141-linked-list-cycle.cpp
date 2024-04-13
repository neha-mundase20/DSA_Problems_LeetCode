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
    bool hasCycle(ListNode *head) {
        bool flag=false;
        
        unordered_set<ListNode*>ust;
        
        ListNode*temp=head;
        
        while(temp!=nullptr){
            if(ust.find(temp)!=ust.end()){  //a cycle is present
                flag=true;
                break;
            }
            ust.insert(temp);
            temp=temp->next;
        }
        return flag;
    }
};