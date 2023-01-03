link -> https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/870493677/
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
        // empty 
        if(head == nullptr) return head;
        ListNode*curr = head;
 
        while(curr!=nullptr){
            if((curr->next!=nullptr)&& curr->val ==curr->next->val){
                // when dupilcate element matched then store it
                ListNode *next_next = curr->next->next;
                // delete dupilcate 
                ListNode *deletetoNode = curr->next;
                delete(deletetoNode);
                //after delete add with next node
                curr->next = next_next;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};
