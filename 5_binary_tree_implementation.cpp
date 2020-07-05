// Implementation of a binary tree

// It is vert intuitive to use recursive function to accomplish 
// search and insert operations. 

#include <iostream>

struct Node{

	int data{};

	Node* left = nullptr;

	Node* right = nullptr;
};

Node* root = nullptr;	// root pointer

// Insert hte value at an appropriate position. 
void Insert(int v){

	// allocate new node
	Node* temp = new Node{};
	temp -> data = v;

	if(root == nullptr){	// empty tree
		root = temp;

	}
	else{

		Node* temp2 = root;
		Node* temp3 = root;

		while(temp3 != nullptr){
			
			if(v <= (temp2 -> data)){	// go left

				temp3 = temp2 -> left;

				if(temp3 == nullptr){

					temp2 -> left = temp;
					break;
				}
			}
			else{	// go right

				temp3 = temp2 -> right;
		
				if(temp3 == nullptr){

					temp2 -> right = temp;
					break;
				}
			
			}
			
			temp2 = temp3;
		}
	}
}

// function to create new node
Node* New_node(int v){

	Node* temp = new Node{};
	temp -> data = v;

	return temp;
}

// Use recersive function to insert a value. 
void Insert_recursive(int v, Node*& troot){

	if(troot == nullptr){	// empty tree
		troot = New_node(v);
	}
	else if(v <= troot -> data){	// go left

		Insert_recursive(v, troot -> left);
	}
	else{

		Insert_recursive(v, troot -> right);
	}
}

// return true is the data is inside the tree
bool Search(int data, Node* troot){

	if(troot == nullptr){	// if empty

		return false;
	}
	else if(troot -> data == data){

		return true;
	}
	else if(data <= troot -> data){

		Search(data, troot -> left);

	}
	else{

		Search(data, troot -> right);

	}

}

int main(){

	Node* r_root = nullptr;

	Insert_recursive(5, r_root);
	Insert_recursive(4, r_root);
	Insert_recursive(10, r_root);
	Insert_recursive(12, r_root);
	Insert_recursive(8, r_root);

	std::cout<< "Enter a int. \n";

	int i{};
	std::cin>> i;

	bool find = Search(i, r_root);

	std::cout<< "find " << i << " ? : " << find << "\n";

}
