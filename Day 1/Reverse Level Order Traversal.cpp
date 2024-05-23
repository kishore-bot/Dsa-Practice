// PROBLEM OF THE DAY
// Tree
// https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1
// EASY

// QUESTIO
/*
Input :
        1
      /   \
     3     2

Output:
3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
*/

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            q.pop();
            ans.push_back(it->data);
            if (it->right)
                q.push(it->right);
            if (it->left)
                q.push(it->left);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}