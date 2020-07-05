// Traverse the binary tree in level-order (read all the nodes in the same level before we visit the next level. )
// Time complexity: O(n)

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
	Insert_recursive(5, root);
	Insert_recursive(3, root);
	Insert_recursive(6, root);
	Insert_recursive(20, root);
	Insert_recursive(2, root);
	
	Level_order_traversal(root);
}
