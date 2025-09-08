#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lowerHead = nullptr;
        ListNode *lowerTail = lowerHead;
        ListNode *higherHead = nullptr;
        ListNode *higherTail = higherHead;
        ListNode *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->val < x)
            {
                if (lowerTail == nullptr)
                {
                    lowerHead = tmp;
                    lowerTail = tmp;
                }
                else
                {
                    lowerTail->next = tmp;
                    lowerTail = lowerTail->next;
                }
            }
            else
            {
                if (higherTail == nullptr)
                {
                    higherHead = tmp;
                    higherTail = tmp;
                }
                else
                {
                    higherTail->next = tmp;
                    higherTail = higherTail->next;
                }
            }
            tmp = tmp->next;
        }
        if (higherHead != nullptr)
            higherTail->next = nullptr;
        if (lowerHead != nullptr)
            lowerTail->next = higherHead;
        else
            lowerHead = higherHead;
        return lowerHead;
    }
};

int main()
{
    Solution sol;
    int n, x;
    cout << "Enter number of nodes in the linked list: ";
    cin >> n;
    cout << "Enter the value of x: ";
    cin >> x;
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    ListNode *result = sol.partition(head, x);
    cout << "Partitioned linked list: ";
    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}