#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void printTree(TreeNode* root)
{
    if (!root)
    {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
class Solution {
public:
    vector<TreeNode*> branches(int start, int end)
    {
        vector<TreeNode*> branchList;
        if(start > end)
            return {nullptr};
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> leftBranches = branches(start,i-1);
            vector<TreeNode*> rightBranches = branches(i+1,end);
            for(TreeNode* l : leftBranches)
            {
                for(TreeNode* r : rightBranches)
                {
                    TreeNode* currentNode = new TreeNode(i);
                    currentNode->left=l;
                    currentNode->right=r;
                    branchList.push_back(currentNode);
                }
            }
        }
        return branchList;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n<1)
            return vector<TreeNode*> ();
        return branches(1,n);
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<TreeNode*> result = sol.generateTrees(n);
    cout << "Number of unique BSTs with values from 1 to " << n << " is: " << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Tree " << i + 1 << ": [";
        printTree(result[i]);
        cout << "]" << endl;
    }
    return 0;
}