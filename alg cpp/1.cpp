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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* current = head;
            while (current && current->next) {
                if (current->val == current->next->val) {
                    // Remove the duplicate node.
                    ListNode* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                } else {
                    // Move to the next distinct element.
                    current = current->next;
                }
            }
            return head;
        }
    };
    