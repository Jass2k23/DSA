#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node(int data,Node*next){
		this->data = data;
		this->next = next;
	}
	Node(int data){
		this->data = data;
		next = NULL;
	}
};

//! print LL
void print(Node* head){
	Node* mover = head;
	while(mover){
		cout<<mover->data<<" ";
		mover = mover->next;
	}
	cout<<endl;
}


//! converting array into LL
Node* conversion(int arr[],int k){
	Node* head = new Node(arr[0]);
	Node* mover = head;
	for(int i=1;i<k;i++){
		Node* temp = new Node(arr[i]);
		mover->next = temp;
		mover = temp;
	}
	return head;
}

//! Deleting a Node
Node* deleteNode(Node* head,int k){
    if(head == NULL)    return head;
	//* if k = 1 (Head)
	if(k==1){
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	//* if k is other position or tail
	int cnt = 1;
	Node* mover = head;
	while(mover){
		Node* prev = mover;
		mover = mover->next;
		cnt++;

		if(cnt == k){
			prev->next = mover->next;
			delete mover;
			break;
		}
	}
	if(cnt<k)
		return NULL;

    return head;
}




int main(){
	int arr [] = {1,2,3,4,5,6};
	Node* head = conversion(arr,6);

	// Node* head_afterDelete = deleteNode(head,1);		// deletes the head

	Node* deleting = deleteNode(head,9);
	print(deleting);
}