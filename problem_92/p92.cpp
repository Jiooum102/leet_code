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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;

        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        // Reverse the sublist from left to right
        ListNode *curr = prev->next;
        ListNode *next = nullptr;
        ListNode *prevRev = nullptr;
        for (int i = 0; i <= right - left; i++)
        {
            next = curr->next;
            curr->next = prevRev;
            prevRev = curr;
            curr = next;
        }

        // Reconnect with the rest of the list
        prev->next->next = curr;
        prev->next = prevRev;
        return dummy.next;
    }
};

int main()
{
    Solution sol;
    ListNode *head = nullptr;
    int n;
    cout << "Enter number of elements in the list: ";
    cin >> n;
    cout << "Enter the elements of the list: ";
    ListNode *tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *newNode = new ListNode(x);
        if (!head)
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
    int left, right;
    cout << "Enter the left index: ";
    cin >> left;
    cout << "Enter the right index: ";
    cin >> right;
    head = sol.reverseBetween(head, left, right);
    cout << "The modified list is: ";
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}