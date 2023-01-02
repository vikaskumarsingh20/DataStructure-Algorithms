class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root; // base case
        queue<Node *> q; // FIFO
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Node *ans = q.front();
                q.pop();
                cout << ans->val << " ";
                if (size != 0)
                {
                    ans->next = q.front();
                }
                if (ans->left)
                    q.push(ans->left);
                if (ans->right)
                    q.push(ans->right);
            }
        }
        return root;
    }
};