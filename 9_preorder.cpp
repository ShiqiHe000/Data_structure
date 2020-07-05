// Traverse the tree in preorder manner: <root><left><right>

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

void preorder(Node* root){

	if(root == nullptr){

		return;
	}

	std::cout<< root -> data << " ";

	preorder(root -> left);
	preorder(root -> right);

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
	
	preorder(root);

	std::cout<< "\n";
}
