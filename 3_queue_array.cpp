// Implement a queue data structure by using an array. 
// The insert, remove, get front/rear, and check empty/full operation should only take constant time. 
// The array queue is treated in a ring manner. 

// The objects in the queue can only be integers. 

#include <iostream>
#include <vector>
#include <cassert>

class Queue{

private:
	std::vector<int> A;
	int front;
	int rear;
	int size;

public:
	Queue(int my_size){

		assert(my_size >= 0 && "The size of the queue cannot be a negative value. \n");

		front = -1;
		rear = -1;
		size = my_size;

		A = std::vector<int>(size);
	}

	bool IsEmpty();

	bool IsFull();

	int Front(){

		if(front == -1){
			std::cout<< "This queue is empty. \n";
			return;
		}

		return A[front];
	}	

	int Rear(){

		if(front == -1){
			std::cout<< "This queue is empty. \n";
			return;
		}
		return A[rear];
	}

	void Emqueue(int v);

	void Dequeue();

};

bool Queue::IsEmpty(){

	if((rear == -1) && (front == -1)){

		return true;
	}
	else{

		return false;
	}
}

// if rear next == front, then the array is full. 
bool Queue::IsFull(){

	int next = (rear + 1) % size;

	if(next == front){

		return true;
	}
	else{

		return false;
	}
	
}

void Queue::Emqueue(int v){

	if(this -> IsEmpty()){	// empty queue

		front = 0;
		rear = 0;

		A[rear]	= v;
	}
	else if(this -> IsFull()){	// queue is full

		std::cout<< "Error: the queue is full, cannot add more iterms. \n";

	}
	else{	// still have space

		rear = (rear + 1) % size;

		A[rear] = v;

	}
}

void Queue::Dequeue(){

	if(this -> IsEmpty()){

		return;
	}
	else if(rear == front){	// only one element

		rear = -1;
		front = -1;
	}
	else{

		front = (++front) % size;	// no need to clear the value, it can be overwritten. 
	}
}


int main(){

	Queue Q(3);

//	std::cout<< "Empty: "<< Q.IsEmpty() << "\n";

	Q.Emqueue(2);
	Q.Emqueue(6);
	Q.Emqueue(9);

	std::cout<< "rear = " << Q.Rear() << "\n";

	Q.Dequeue();

	std::cout<< "front = "<< Q.Front() << "\n";
}
