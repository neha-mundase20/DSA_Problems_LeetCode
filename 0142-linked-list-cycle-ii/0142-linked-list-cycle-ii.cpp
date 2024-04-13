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
        unordered_set<ListNode*> visited;
        
        ListNode*temp=head;
        
        while (temp != nullptr) {
            if (visited.find(temp) != visited.end()) {
                return temp; // Found the node where the cycle is present and tail again                                    //connects to the node at the temp address
            }
            visited.insert(temp); // Node isn't already visited, insert the current node into the set
            temp = temp->next;
        }
        
        return nullptr; // No cycle found
    }
};