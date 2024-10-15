#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

void count_of_nodes(struct node *head)
{
	int count = 0;
	if (head == NULL)
	{
		cout << "LinkedList is empty" << endl;
		return;
	}
	struct node *temp = head;

	while (temp != NULL)
	{
		count++;
		temp = temp->link;
	}

	cout << count << endl;
}

void print_data(struct node *head)
{
	if (head == NULL)
	{
		cout << "LinkedList is empty";
		return;
	}

	struct node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->link;
	}
	cout << "NULL" << endl;
}

struct node *add_at_beg(struct node *head, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;

	temp->link = head;
	head = temp;

	return head;
}

void add_at_end(struct node *head, int data)
{
	struct node *ptr, *temp;
	ptr = head;

	temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->link = NULL;

	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = temp;
}

void add_beg(struct node **head, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->link = NULL;

	ptr->link = *head;
	*head = ptr;
}

void add_at_pos(struct node *head, int data, int pos)
{

	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->link = NULL;

	struct node *temp = head;

	pos--;
	while (pos != 1)
	{
		temp = temp->link;
		pos--;
	}

	ptr->link = temp->link;
	temp->link = ptr;
}

void del_pos(struct node **head, int pos)
{
	struct node *prev = *head;
	struct node *curr = *head;

	if (*head == NULL)
	{
		cout << "LinkedList is empty";
		return;
	}
	else if (pos == 1)
	{
		*head = curr->link;
		free(curr);
		curr = NULL;
	}
	else
	{
		while (pos != 1)
		{
			prev = curr;
			curr = curr->link;
			pos--;
		}
		prev->link = curr->link;
		free(curr);
		curr = NULL;
	}
}

int main()
{

	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));

	head->data = 45;
	head->link = NULL;

	struct node *current = (struct node *)malloc(sizeof(struct node));

	current->data = 46;
	current->link = NULL;
	head->link = current;

	current = (struct node *)malloc(sizeof(struct node));

	current->data = 47;
	current->link = NULL;

	head->link->link = current;

	// head = add_at_beg(head, 44);

	add_beg(&head, 44);
	add_at_pos(head, 48, 2);

	print_data(head); // 45->46->47->NULL

	cout << "after deleting 2nd node" << endl;
	del_pos(&head, 2);

	print_data(head);

	return 0;
}
