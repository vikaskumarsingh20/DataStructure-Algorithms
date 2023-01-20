class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (!head || !head->next)
            return head;

        auto ans = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return ans;
    }
};