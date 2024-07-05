#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

vector<vector<int>> LevelOrderTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            level.push_back(node->data);
        }

        ans.push_back(level);
    }

    return ans;
}

vector<int> itrPreOrder(TreeNode *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        ans.push_back(node->data);

        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }

    return ans;
}

vector<int> preInPostTraversal(TreeNode *root)
{
    vector<int> Pre, In, Post;
    if (!root)
        return Pre;

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto node = st.top();
        st.pop();

        if (node.second == 1)
        {
            Pre.push_back(node.first->data);
            node.second++;
            st.push(node);

            if (node.first->left)
                st.push({node.first->left, 1});
        }
        else if (node.second == 2)
        {
            In.push_back(node.first->data);
            node.second++;
            st.push(node);

            if (node.first->right)
                st.push({node.first->right, 1});
        }
        else
        {
            Post.push_back(node.first->data);
        }
    }
}

int cameras(TreeNode *root, int camera[])
{

    // need a camera/cover = -1;
    // if covered   = 1;
    //  if camera = 0;

    if (root == nullptr)
        return 1;

    int lft = cameras(root->left, camera);
    int right = cameras(root->right, camera);

    // first check if any of the left/right camera needs a camera or a cover
    if (lft == -1 || right == -1)
    {
        camera[0] += 1;
        return 0;
    } // check if any of my child have camera or not (if yes, means im covered)
    else if (lft == 0 || right == 0)
    {
        return 1;
    }
    else
    { // now i need a camera or cover
        return -1;
    }
}

int cameraOnBinaryTree(TreeNode *root)
{
    int camera[1] = {0};
    int need = cameras(root, camera);

    if (need == -1)
        camera[0] += 1;

    return camera[0];
}

TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q, int &ans)
{
    if (root == nullptr)
        return nullptr;

    TreeNode *lf = LCA(root->left, p, q, ans);
    TreeNode *rh = LCA(root->right, p, q, ans);

    if (root == p || root == q)
    {
        return root;
    }

    if (lf && rh)
    {
        ans = root->data;
        return root;
    }

    if (lf)
        return lf;
    return rh;
}

int main()
{
    struct TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> preorder = itrPreOrder(root);
    for (int data : preorder)
    {
        cout << data << " ";
    }

    cout << endl
         << endl;

    cout << "Level order traversal" << endl;
    vector<vector<int>> lot = LevelOrderTraversal(root);

    for (auto level : lot)
    {
        for (int data : level)
        {
            cout << data << " ";
        }
        cout << endl;
    }
    int ans;
    LCA(root, root->right->left, root->right->right, ans);
    cout << ans << endl;
}