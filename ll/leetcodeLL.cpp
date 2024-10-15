#include <bits/stdc++.h>
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
    ListNode *removeElements(ListNode *head, int val)
    {

        ListNode dummy(0);
        dummy.next = head;

        ListNode *prev = &dummy;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            ListNode *temp2 = curr->next;
            if (curr->val == val)
            {
                prev->next = temp2;
                curr = temp2;
            }
            else
            {
                prev = curr;
                curr = temp2;
            }
        }

        return head;
    }
};

int main()
{
    // Creating a linked list 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode *newList = solution.removeElements(head, 2);

    ListNode *current = newList;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    // Output should be: 5 4 3 2 1

    return 0;
}