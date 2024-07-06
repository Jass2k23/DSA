#include <bits/stdc++.h>
using namespace std;


//! Node creation
class Node{
    public:
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
    }
};


//! Converting arr into LL
Node* convert2LL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}



//! Traversal and length
void traversal(Node* head){
    Node* mover = head;
    int cnt = 0;
    while(mover){
        cout<<mover->data<<" ";
        mover = mover->next;
        cnt++;
    }
    cout<<endl;
    cout<<cnt<<endl;
}

int main(){
    vector<int>arr;
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(10);
    Node* head = convert2LL(arr);
    
    traversal(head);
}