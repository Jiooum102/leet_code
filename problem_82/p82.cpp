#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        while(head!=nullptr&&head->next!=nullptr&&head->next->val==head->val)
        {
            int tmp=head->val;
            while(head!=nullptr&&head->val==tmp)
            {
                ListNode *prev=head;
                head=head->next;
                delete prev;
            }
        }
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=nullptr)
        {
            if(curr->next!=nullptr&&curr->next->val==curr->val)
            {
                int tmp=curr->val;
                while(curr!=nullptr&&curr->val==tmp)
                {
                    ListNode* tmpPtr=curr;
                    curr=curr->next;
                    delete tmpPtr;
                }
                prev->next=curr;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int n;
    cout << "Enter number of elements in the linked list: ";
    cin >> n;
    cout << "Enter the elements of the linked list in sorted order: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    ListNode* result = sol.deleteDuplicates(head);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
