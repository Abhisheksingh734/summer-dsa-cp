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

vector<vector<int>> zigZagTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    bool flag = true;

    while (!q.empty())
    {
        int size = q.size();

        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            int index = (flag) ? i : size - i - 1;

            level[index] = node->data;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        flag = !flag;
        ans.push_back(level);
    }

    return ans;
}

int height(TreeNode *root, int &maxy)
{
    if (!root)
        return 0;

    int lf = height(root->left, maxy);
    int rh = height(root->right, maxy);

    maxy = max(lf + rh + 1, maxy);

    return 1 + max(lf, rh);
}

int diameter(TreeNode *root)
{
    int maxy = INT_MIN;

    int ans = height(root, maxy);
    return maxy;
}

bool check(TreeNode *root, long long min, long long max)
{
    if (!root)
        return true;

    if (root->data <= min || root->data >= max)
    {
        return false;
    }

    return check(root->left, min, root->data) && check(root->right, root->data, max);
}

TreeNode *insert(TreeNode *root, int tar)
{

    if (!root)
        return new TreeNode(tar);

    TreeNode *curr = root;

    while (true)
    {
        if (curr->data > tar)
        {
            if (curr->left)
                curr = curr->left;
            else
            {
                curr->left = new TreeNode(tar);
            }
        }
        else
        {
            if (curr->right)
                curr = curr->right;
            else
            {
                curr->right = new TreeNode(tar);
            }
        }
    }

    return root;
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;

    queue<pair<TreeNode *, pair<int, int>>> q;

    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        TreeNode *node = p.first;
        int x = p.second.first, y = p.second.second;

        mp[x][y].insert(node->data);

        if (node->left)
        {
            q.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto x : mp)
    {
        vector<int> level;
        for (auto y : x.second)
        {
            level.insert(level.end(), y.second.begin(), y.second.end());
        }
        ans.push_back(level);
    }

    return ans;
}

vector<int> topView(TreeNode *root)
{
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    int level = 0;
    q.push({root, level});

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front().first;
            q.pop();
            int dist = q.front().second;

            if (mp.find(node->data) == mp.end())
            {
                mp[dist] = node->data;
            }

            if (node->left)
            {
                q.push({node->left, level - 1});
            }
            if (node->right)
            {
                q.push({node->right, level + 1});
            }
        }
    }

    vector<int> ans;

    for (auto x : mp)
    {
        ans.push_back(x.second);
    }

    return ans;
}

void rightView(TreeNode *root, int level, vector<int> &res)
{
    if (!root)
        return;

    if (res.size() == level)
        res.push_back(root->data);

    rightView(root->right, level + 1, res);
    rightView(root->left, level + 1, res);
}

int main()
{
    // level 1
    TreeNode *root = new TreeNode(50);

    // level 2
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);

    // level 3
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(35);
    root->right->left = new TreeNode(58);
    root->right->right = new TreeNode(65);

    // int ans = diameter(root);
    // cout << ans << endl;

    // bool isBST = check(root, LLONG_MIN, LLONG_MAX);
    // cout << isBST;

    vector<vector<int>> ans2 = verticalTraversal(root);

    vector<int> top = topView(root);

    for (int data : top)
    {
        cout << data << " ";
    }
}