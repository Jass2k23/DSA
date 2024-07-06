#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* back;
    Node* back;
    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
        back = NULL;
    }
};

//! Conversion of Array into DLL
Node *constructDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *back = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], NULL, back);
        back->next = temp;
        back = temp;
    }
    return head;
}

//!  Insert at end of Doubly Linked List
Node *insertAtTail(Node *head, int k)
{
    if (head == NULL)
    {
        Node *temp = new Node(k);
        return temp;
    }
    Node *mover = head;
    while (mover->next)
    {
        mover = mover->next;
    }
    Node *temp = new Node(k, NULL, mover);
    mover->next = temp;

    return head;
}

//! Delete Last Node of a Doubly Linked List
Node *deleteLastNode(Node *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        Node *temp = head;
        head = NULL;
        delete temp;
        return head;
    }
    Node *mover = head;
    while (mover->next->next)
    {
        mover = mover->next;
    }
    Node *temp = mover->next;
    delete temp;
    mover->next = NULL;

    return head;
}

//! Reverse A Doubly Linked List
Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *current = head;
    Node* last = NULL;
    while (current)
    {
        last = current->back;
        current->back = current->next;
        current->next = last;
        //* moving the current node for traversal
        current = current->back;
    }
    return last->back;
}

int main()
{
}