// Find the height of a binary tree.  

// The height is the maximum edge number of a node to a leaf. 


#include <iostream>

struct Node{

	int data{};

	Node* left = nullptr;

	Node* right = nullptr;
};


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

// Recursive search. 
// return true is the data is inside the tree. 
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

// go left towards the end. 
int Find_min_recursive(Node* troot){

	if(troot == nullptr){	// empty tree
		std::cout<< "Empty tree. \n";
		return 0;
	}
	else if(troot -> left == nullptr){	// no left

		return troot -> data;
	}
	else{

		int i = Find_min_recursive(troot -> left);

		return i;
	}

}

int Find_min_interative(Node* troot){

	Node* temp = troot;

	
	if(troot == nullptr){	// empty tree
		std::cout<< "Empty tree. \n";
		return 0;
	}

	while(temp -> left != nullptr){

		temp = temp -> left;
	}

	return temp -> data;
}

// Recursive funciton to find height. 
int Find_height(Node* node){

	if(node == nullptr){
		return -1;
	}	
	else{	// return the max(left, right) + 1

		int left = Find_height(node -> left);
		int right = Find_height(node -> right);
		
		int max = (left >= right) ? left : right;

		return (max + 1);
	}
	


}


int main(){

	Node* root = nullptr;

	Insert_recursive(5, root);
	Insert_recursive(4, root);
	Insert_recursive(16, root);
	Insert_recursive(5, root);
	Insert_recursive(3, root);
	Insert_recursive(6, root);
	Insert_recursive(20, root);
	Insert_recursive(2, root);

	int i_min = Find_min_interative(root);
	int r_min = Find_min_recursive(root);

	std::cout<< "min interative " << i_min << "\n";
	std::cout<< "min recursive " << r_min << "\n";

	int r_height = Find_height(root);

	std::cout<< "height of the root node: " << r_height << "\n";


}
