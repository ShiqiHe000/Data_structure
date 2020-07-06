// Delete a target node in BST and still preserve the BST

// Three situations:
// 1. node with no child: delete. 
// 2. node with one child: form new link and delete. 
// 3. node with two children: find the maximum in target node's the right subtree, and replace the target node with the 
// 	minimum value, and then delete the duplicated value. 

#include <iostream>
#include <queue>

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

// return pointer to the most left node. 
Node* Min_node(Node* node){

	if(node -> left == nullptr){	// leaf node

		return (node);
	}
	else{

		return (Min_node(node -> left));
	}

}

// Delete function. 
void Delete(Node*& root, int value){

	if(root == nullptr){

		return;
	}
	else if(value < root -> data){	// find the data in the left subtree 

		Delete(root -> left, value);
	}
	else if(value > root -> data){	// find the data in hte right subtree

		Delete(root -> right, value);

	}
	else{	// locate the data
		
		if(root -> left == nullptr && root -> right == nullptr){	// no child

			delete root;

			root = nullptr;
		}
		else if(root -> left == nullptr){	// only has a right child. 
		
			Node* temp = root;
			
			root = root -> right;	// move to the right child 

			delete temp;
		}
		else if(root -> right == nullptr){	// only has a left child. 
		
			Node* temp = root;
			
			root = root -> left;	// move to the left child 

			delete temp;
		}
		else{	// this node has two children

			// find the minimum data in the right subtree
			Node* minp = Min_node(root -> right);

			root -> data = minp -> data;

			Delete(root -> right, root -> data);

		}
	}

}


void Level_order_traversal(Node* root){

	if(root == nullptr){
		std::cout<< "Empty tree. \n";
		return;
	}

	std::queue<Node*> Q{};	// a queue of pointers to nodes. 

	Q.emplace(root);

	while(!Q.empty()){

		// print itself
		std::cout<< Q.front() -> data << " ";

		// put left and right to the queue
		if(Q.front() -> left != nullptr){
		
			Q.emplace(Q.front() -> left);
		}

		if(Q.front() -> right != nullptr){
		
			Q.emplace(Q.front() -> right);
		}

		Q.pop();
	}
	std::cout<< "\n";
}

int main(){

	Node* root = nullptr;

	Insert_recursive(5, root);
	Insert_recursive(4, root);
	Insert_recursive(16, root);
	Insert_recursive(8, root);
	Insert_recursive(20, root);
	Insert_recursive(7, root);
	Insert_recursive(9, root);
	Insert_recursive(17, root);
	Insert_recursive(25, root);

	Level_order_traversal(root);

	Delete(root, 5);

	Level_order_traversal(root);
}
