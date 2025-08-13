#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        if(size == n)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            int pos = size - n, Next = 1;
            temp = head;
            while(Next < pos)
            {
                temp = temp->next;
                Next++;
            }
            ListNode* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
        return head;
    }
};
int main()
{
    Solution sol;
    int size;
    cout << "Enter size of list: ";
    cin >> size;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i=0; i<size; i++)
    {
        int val;
        cout << "Enter value for node " << i+1 << ": ";
        cin >> val;
        ListNode* newNode = new ListNode(val);
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
    cout << "Enter the position from the end to remove: ";
    int n;
    cin >> n;
    head = sol.removeNthFromEnd(head, n);
    ListNode* temp = head;
    cout << "Updated list after removal: ";
    while(temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}