#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

//!  Delete all occurrences of a given key in a doubly linked list
Node *deleteAllOccurrences(Node *head, int key){
    if(head == nullptr)
        return head;
    
    Node* temp = head;

    while(temp){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            Node* frwd = temp->next;
            Node* back = temp->prev;

            if(frwd)
                frwd->prev = back;
            if(back)
                back->next = frwd;
            
            free(temp);
            temp = frwd;
        }
        else{
            temp = temp->next;
        }
    }

    return head;
}


//! Find pairs with given sum in doubly linked list
Node* returnTail(Node* head){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    return temp;
}

vector<pair<int, int>> findPairs(Node* head, int k){
    vector<pair<int, int>> ans;
    Node* left = head; 
    Node* right = returnTail(head);

    while(left->data < right->data){
        int sum = left->data + right->data;

        if(sum == k){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum < k){
            left = left->next;
        }
        else
            right = right->prev;
    }

    return ans;
}



//!  Remove duplicates from a sorted Doubly Linked List
Node * removeDuplicates(Node *head){
    Node* temp = head;
    while(temp){
        Node* nextNode = temp->next;
        while(nextNode and temp->data == nextNode->data){
            nextNode = nextNode->next;
        }
        temp->next = nextNode;
        if(nextNode)
            nextNode->prev = temp;
            
        temp = temp->next;
    }

    return head;
}