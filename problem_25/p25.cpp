#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        int Arr[k];
        int count = 0;
        ListNode *temphead = head;
        ListNode *valget = head;
        while (valget != nullptr) {
            Arr[count++] = valget->val;
            valget = valget->next;
            if(count==k)
            {
                for(count = k - 1; count >= 0; --count)
                {
                    temphead->val = Arr[count];
                    temphead = temphead->next;
                }
                count = 0;
            }
        }
        return head;
    }
};
int main()
{
    int n,k;
    cout << "Enter number of elements in linked list : ";
    cin >> n;
    cout << "Enter the value of k : ";
    cin >> k;
    Solution sol;
    ListNode *head = nullptr, *tail = nullptr;
    for(int i=0;i<n;++i)
    {
        int val;
        cout << "Enter value for node " << i+1 << " : ";
        cin >> val;
        ListNode *newNode = new ListNode(val);
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    head = sol.reverseKGroup(head, k);
    cout << "Reversed linked list (in groups of " << k << "): ";
    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}