#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *CreateTree(vector<string> vals)
{
    if (vals.empty())
        return nullptr;
    int size = vals.size();
    TreeNode *root = new TreeNode(stoi(vals[0]));
    vals.erase(vals.begin());
    vector<TreeNode *> nodes;
    nodes.push_back(root);
    while(vals.size()!= 0)
    {
        int add = 2*nodes.size();
        for(int i=0;i<add;i++)
        {
            if(vals.empty())
                break;
            if (vals[0] == "n")
            {
                vals.erase(vals.begin());
                if (i % 2 == 0)
                {
                    nodes[i / 2]->left = nullptr;
                }
                else
                {
                    nodes[i / 2]->right = nullptr;
                    nodes.erase(nodes.begin());
                }
                continue;
            }
            TreeNode *node = new TreeNode(stoi(vals[0]));
            if (i % 2 == 0)
            {
                nodes[i / 2]->left = node;
            }
            else
            {
                nodes[i / 2]->right = node;
                nodes.erase(nodes.begin());
            }
            vals.erase(vals.begin());
            nodes.push_back(node);
        }
    }
    return root;
}
class Solution {
public:
    bool func(TreeNode* curr, long long currMin, long long currMax) {
        if (!curr)
            return true;
        if (curr->val >= currMax || curr->val <= currMin)
            return false;
        return func(curr->left, currMin, curr->val) &&
               func(curr->right, curr->val, currMax);
    }
    bool isValidBST(TreeNode* root) { return func(root, LLONG_MIN, LLONG_MAX); }
};

int main()
{   Solution sol;
    cout << "Creating a binary search tree." << endl;
    vector<string> vals;
    cout << "Enter values for the nodes (n for null, s for stop): ";
    while (true)
    {
        string input;
        cin >> input;
        if (input == "s")
            break;
        vals.push_back(input);
    }
    TreeNode *root = CreateTree(vals);
    bool result = sol.isValidBST(root);
    cout << (result ? "Yes, it is a valid BST." : "No, it is not a valid BST.") << endl;
    return 0;
}