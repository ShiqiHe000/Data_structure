// Implement a queue data structure by using a linked list. 
// In order to perform enqueue and dequeue operation with O(1), 
// we need to pointers in the linked list, pointing to the head/front
// and the rear/tail respectively. 

#include <iostream>

// struct for a linked list. 
struct Node{

	int data;
	Node* next;
};
	
Node* front = nullptr;
Node* rear = nullptr;

void Enqueue(int v);
void Dequeue();
void Print_Q();

int main(){

	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Dequeue();

	Print_Q();

}

void Enqueue(int v){

	Node* temp = new Node();
	temp -> data = v;
	temp -> next = nullptr;

	if(front == nullptr && rear == nullptr){	// empty queue


		front = temp;
		rear = temp;
	}
	else{
	
		rear -> next = temp;

		rear = temp;
	}
}


void Dequeue(){

	if(front == nullptr && rear == nullptr){	// empty queue
		return;
	}
	else if(front == rear){	// only one iterm

		front = nullptr;
		rear = nullptr;
	}
	else{

		Node* temp = front -> next;

		delete front;

		front = temp;
	}

}


void Print_Q(){

	Node* temp = front;

	while(temp != nullptr){

		std::cout<< temp -> data << " ";

		temp = temp -> next;

	}
	std::cout<< "\n";

}
