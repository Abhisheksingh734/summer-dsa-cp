#include <bits/stdc++.h>

using namespace std;

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *findMid(struct node *head)
// {

//     if (head == nullptr)
//     {
//         return head;
//     }

//     struct node *fast = head;
//     struct node *slow = head;

//     while (fast != nullptr && fast->next != nullptr)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }

//     return slow;
// }

// struct node *reverseList(struct node *head)
// {
//     if (head == nullptr || head->next == nullptr)
//     {
//         return head;
//     }
//     struct node *prev = nullptr;
//     struct node *current = head;
//     struct node *next = nullptr;

//     while (current != nullptr)
//     {
//         next = current->next; // Store the next node
//         current->next = prev; // Reverse the current node's pointer
//         prev = current;       // Move prev pointer forward
//         current = next;       // Move current pointer forward
//     }

//     return prev;
// }

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *left;
    ListNode *right;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode *mergeSorted(ListNode *l1, ListNode *l2)
// {
// }

// ListNode* merge(ListNode*l1, ListNode*l2){
//     ListNode* c1 = l1;
//     ListNode* c2 = l2;
//     ListNode* pre = nullptr;
//     ListNode* fwd = nullptr;

//     while(c1 !=NULL && c2|=NULL){
//         fwd = c1->next;
//         c1->next = c2;

//         pre = c1;
//         c1 = fwd;

//         //manage for second list
//         fwd = c2->next;
//         c2->next = c1;

//         pre = c2;
//         c2 = fwd;

//     }

//     if(c1!=NULL || c2 != NULL){
//         pre->next =
//     }
// }

// ListNode *merge(ListNode *left, ListNode *right)
// {
//     if (!left)
//         return right;
//     if (!right)
//         return left;

//     if (left->val <= right->val)
//     {
//         left->next = merge(left->next, right);
//         return left;
//     }
//     else
//     {
//         right->next = merge(left, right->next);
//         return right;
//     }
// }

// ListNode *getMiddle(ListNode *head)
// {
//     if (!head)
//         return nullptr;

//     ListNode *slow = head;
//     ListNode *fast = head->next;

//     while (fast && fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }

//     return slow;
// }

// ListNode *mergeSort(ListNode *head)
// {
//     if (!head || !head->next)
//         return head;

//     ListNode *middle = getMiddle(head);
//     ListNode *nextOfMiddle = middle->next;

//     middle->next = nullptr;

//     ListNode *left = mergeSort(head);
//     ListNode *right = mergeSort(nextOfMiddle);

//     return merge(left, right);
// }

// bool isPalindrome(ListNode *head)
// {
// }

// //         ListNode *temp1 = list1;
//         ListNode *temp2 = list2;

//         ListNode dummy;
//         ListNode *curr = &dummy;

//         while(temp1 !=nullptr && temp2 !=nullptr){
//             if(temp1->val < temp2->val){
//                 curr->next = temp1;
//                 temp1 = temp1->next;
//             }else{
//                 curr->next = temp2;
//                 temp2 = temp2->next;
//             }

//             curr = curr->next;
//         }

//         if(temp1 != nullptr){
//             curr->next = temp1;
//         }else{
//             curr->next = temp2;
//         }

//         return dummy.next;

//     }
// };

// struct node *mergeList(struct node *list1, struct node *list2)
// {
//     struct node *t1 = list1;
//     t1->next = nullptr;
//     struct node *t2 = list2;
//     t2->next = nullptr;

//     struct node *curr = nullptr;

//     while (t1->next != nullptr && t2->next != nullptr)
//     {
//     }
// }

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *nextTemp = curr->next; // Save the next node
        curr->next = prev;               // Reverse the current node's pointer
        prev = curr;                     // Move prev to current node
        curr = nextTemp;                 // Move to the next node
    }

    return prev; // New head of the reversed list
}

ListNode *sumOfLists(ListNode *list1, ListNode *list2)
{

    ListNode *revList1 = reverseList(list1);
    ListNode *revList2 = reverseList(list2);

    ListNode dummy(0); // Dummy node to simplify the code
    ListNode *curr = &dummy;

    int carry = 0;
    while (revList1 && revList2)
    {

        int sum = carry;
        if (revList1)
        {
            sum += revList1->val;
            revList1 = revList1->next;
        }
        if (revList2)
        {
            sum += revList2->val;
            revList2 = revList2->next;
        }

        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    return reverseList(dummy.next);
}

bool hasCycle(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        if (!head || !head->next)
        {
            return false;
        }

        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

vector<int> preOrder(ListNode *root)
{
    if (root == nullptr)
    {
        return {};
    }

    stack<ListNode *> st;
    st.push(root);
    vector<int> ans;
    while (!st.empty())
    {
        ListNode *node = st.top();
        ans.push_back(node->val);
        st.pop();

        if (node->right)
        {
            st.push(node->right);
        }
        if (node->left)
        {
            st.push(node->left);
        }
        }

    return ans;
}

int main()
{

    ListNode *list1 = new ListNode(7);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(6);

    ListNode *list2 = new ListNode(5);
    list2->next = new ListNode(9);
    list2->next->next = new ListNode(2);

    ListNode *result = sumOfLists(list1, list2);

    while (result != nullptr)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
}
