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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            count++;
            tmp = tmp->next;
        }
        if (count < 2||k%count==0)
            return head;
        int pos = count - k % count;
        ListNode* cur = nullptr;
        tmp = head;
        for (int i = 1; i <= count; i++) {
            if (i == pos) {
                cur = tmp;
                tmp = tmp->next;
                cur->next = nullptr;
                cur = tmp;
            } else if (i == count) {
                tmp->next = head;
                break;
            } else
                tmp = tmp->next;
        }
        return cur;
    }
};
int main() {
    Solution sol;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int n, k, val;
    cout << "Enter number of elements in the linked list: ";
    cin >> n;
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout << "Enter the number of positions to rotate: ";
    cin >> k;

    ListNode* result = sol.rotateRight(head, k);
    
    cout << "Rotated linked list: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}