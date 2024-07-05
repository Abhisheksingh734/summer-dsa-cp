#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for binary tree node.
struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct pr
{
    ListNode *root;
    int state;

    pr() {}

    pr(ListNode *rt, int x) : state(x), root(rt) {}
};

vector<int> preOrder(ListNode *root)
{
    if (root == nullptr)
    {
        return {};
    }

    stack<ListNode *> st;
    st.push(root);
    vector<int> ans;

    while (!st.empty())
    {
        ListNode *node = st.top();
        st.pop();
        ans.push_back(node->val);

        if (node->right)
        {
            st.push(node->right);
        }
        if (node->left)
        {
            st.push(node->left);
        }
    }

    return ans;
}

int main()
{

    ListNode *root = new ListNode(1);
    root->left = new ListNode(2);
    root->right = new ListNode(3);
    root->left->left = new ListNode(4);
    root->left->right = new ListNode(5);

    std::vector<int> result = preOrder(root);

    // Output the preorder traversal result: 1 -> 2 -> 4 -> 5 -> 3
    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
