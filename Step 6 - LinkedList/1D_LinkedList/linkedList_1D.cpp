#include <bits/stdc++.h>
using namespace std;

//* Definition of linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

//! Insert Node at the beginning
Node *insertAtFirst(Node *head, int newValue)
{
    Node *newHead = new Node(newValue);
    newHead->next = head;
    head = newHead;
    return head;
}

//! Count nodes of LL
int length(Node *head)
{
    if (head == NULL)
        return 0;
    Node *mover = head;
    int cnt = 0;
    while (mover)
    {
        mover = mover->next;
        cnt++;
    }
    return cnt;
}

//! Search in LL
// Following is the class structure of the Node class:

// template <typename T>
// class LLNode
// {
// public:
//     T data;
//     LLNode<T> *next;
//     LLNode()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }
//     Node(T data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
//     Node(T data, T *next)
//     {
//         this->data = data;
//         this->next = next;
//     }
// };

// int searchInLinkedList(LLNode<int> *head, int k)
// {
//     LLNode<int> *mover = head;
//     while (mover)
//     {
//         if (mover->data == k)
//             return 1;
//         mover = mover->next;
//     }
//     return 0;
// }

//! Deleting a Node
Node *deleteNode(Node *head, int k)
{
    if (head == NULL)
        return head;
    //* if k = 1 (Head)
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    //* if k is other position or tail
    int cnt = 1;
    Node *mover = head;
    while (mover)
    {
        Node *prev = mover;
        mover = mover->next;
        cnt++;

        if (cnt == k)
        {
            prev->next = mover->next;
            delete mover;
            break;
        }
    }
    if (cnt < k)
        return NULL;

    return head;
}

//! Deleting tail
Node *delete_tail(Node *head)
{
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

int main()
{
}