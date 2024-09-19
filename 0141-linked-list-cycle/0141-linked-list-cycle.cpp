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
        unordered_set<ListNode*>st;

        ListNode*temp=head;

        while(temp!=nullptr){
            if(st.find(temp)!=st.end()){    
                //If already traversed node is found
                return true;
            }
            else{
                //If already traversed node isn't found
                st.insert(temp);
                temp=temp->next;
            }
        }
        return false;
    }
};