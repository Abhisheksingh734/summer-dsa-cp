#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list
template <typename T>
struct ListNode
{
    T value;
    ListNode *next;
    ListNode(T x) : value(x), next(nullptr) {}
};

ListNode<int> *solution(ListNode<int> *a, ListNode<int> *b)
{
    stack<int> s1, s2;

    // Push all values from the linked lists into the stacks
    while (a != nullptr || b != nullptr)
    {
        if (a != nullptr)
        {
            s1.push(a->value);
            a = a->next;
        }
        if (b != nullptr)
        {
            s2.push(b->value);
            b = b->next;
        }
    }

    int x = 0;
    ListNode<int> *temp = nullptr;

    // Perform addition using the stacks
    while (!s1.empty() || !s2.empty() || x != 0)
    {
        if (!s1.empty())
            x += s1.top(), s1.pop();
        if (!s2.empty())
            x += s2.top(), s2.pop();

        // Create a new node for the result
        ListNode<int> *n1 = new ListNode<int>(x % 10000);
        n1->next = temp;
        temp = n1;

        // Carry over for the next digits
        x /= 10000;
    }

    return temp;
}

// Function to print the linked list for verification
void printList(ListNode<int> *head)
{
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode<int> *a = new ListNode<int>(1234);
    a->next = new ListNode<int>(5678);
    a->next->next = new ListNode<int>(9101);

    ListNode<int> *b = new ListNode<int>(4321);
    b->next = new ListNode<int>(8765);
    b->next->next = new ListNode<int>(1019);

    ListNode<int> *result = solution(a, b);

    // Print the result linked list
    printList(result); // Expected output: 5556 4414 0120

    return 0;
}
