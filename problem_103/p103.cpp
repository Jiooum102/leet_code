#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *addNode(int &left)
{
    string stringVal;
    cout << "Enter value of node (or n for null): ";
    cin >> stringVal;
    if (stringVal == "n")
        return nullptr;
    int val = stoi(stringVal);
    TreeNode *newNode = new TreeNode(val);
    left--;
    if (left > 0)
    {
        cout << "Adding left child of " << val << endl;
        newNode->left = addNode(left);
    }
    if (left > 0)
    {
        cout << "Adding right child of " << val << endl;
        newNode->right = addNode(left);
    }
    return newNode;
}

class Solution {
public:
    void getValue(vector<vector<int>>& res, int level, TreeNode* cur)
    {
        if(level>=res.size())
            res.push_back({});
        if(level%2)
            res[level].insert(res[level].begin(),cur->val);
        else
            res[level].push_back(cur->val);
        if(cur->left!=nullptr)
            getValue(res,level+1,cur->left);
        if(cur->right!=nullptr)
            getValue(res,level+1,cur->right);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        getValue(res,0,root);
        return res;        
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "The tree is empty." << endl;
        return 0;
    }
    TreeNode *root = addNode(n);
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    cout << "Zigzag Level Order Traversal of the binary tree is: " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << ", ";
        }
        cout << " ]" << endl;
    }
    return 0;
}