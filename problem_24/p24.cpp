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
void Swap(ListNode* a, ListNode* b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = head->next;
        ListNode* tmp=head;
        int i=0;
        while (newHead) {
            if(i%2==0)
            {
                Swap(tmp, newHead);
            }
            i++;
            tmp = newHead;
            newHead = newHead->next;
        }
        return head;
    }
};
int main() {
    int n;
    cout << "Enter number of elements in linked list : ";
    cin >> n;
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
    Solution sol;
    head = sol.swapPairs(head);
    cout << "Swapped linked list: ";
    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}