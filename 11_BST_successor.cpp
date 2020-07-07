// Two algorithms

// First: find the successor node of a specific node in the BST treei in infix order. 
// Algorithm: 
// case 1: node has right subtree: go to the deepest leftmost node the the right subtree. 
// case 2: node does not have right subtree: go to the nearest ancestor for which given node 
// 		would be in the left subtree. 


// Second: find the predecessor of a sepcific node. 
// Algorithm: 
// case 1: node has left subtree: go to the deepest rightmost node the the left subtree. 
// case 2: node does not have left subtree: go to the nearest ancestor for which given node 
// 		would be in the right subtree. 



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

// The the node with value data and return the pointer to such node. 
Node* Find(Node* root, int data){

	if(root == nullptr){

		return nullptr;
	}
	else if(root -> data == data){	// find it
		return root;
	}
	else if(root -> data < data){	// go right

		return (Find(root -> right, data));
	}
	else{	// go left

		return (Find(root -> left, data));
	}

}

// Use the pointer to the root node and the value of the target node and return
// the pointer to the successor node. 
Node* Inorder_successor(Node* root, int data){

	// search the node - O(h)
	Node* current = Find(root, data);
//	std::cout<< "find " << current -> data << "\n";

	if(current == nullptr){	// not find
		std::cout<< "Not find this value. \n";
		return nullptr;
	}
	// if this node has right subtreei, go to the leftmost node in the right subtree
	if(current -> right != nullptr){

		Node* temp = current -> right;

		while(temp -> left != nullptr){	// O(h)

			temp = temp -> left;
		}
		return temp;	
	}
	else{	// if this node has no right subtree, go the the nearest ancestor that this node is in its left subtree. 
		// O(h)
		Node* successor = nullptr;
		Node* ancestor = root;

		while(ancestor != current){	

			if(ancestor -> data >= current -> data ){	// current node is in the left subtree

				successor = ancestor;	// this ancestor might be the succesor. 
				ancestor = ancestor -> left;
			}
			else{
				
				ancestor = ancestor -> right;
			}
			
		}

		return successor;
	}


}

// Find the predecessor of the node with data. Return the pointer to predecessor. 
// root: root node. 
Node* Predecessor(Node* root, int data){

	if(root == nullptr){

		return nullptr;
	}

	// find this node
	Node* current = Find(root, data);

	if(current == nullptr){	// not find
		std::cout<< "Not find this value. \n";
		return nullptr;
	}
	
	if(current -> left != nullptr){	// case 1: has left subtree, go deepest right

		Node* temp = current -> left;

		while(temp -> right != nullptr){

			temp = temp -> right;
		}

		return temp;
	}
	else{	// case 2: has no left subtree, find the nearest ancestor that current node is in its right subtree. 

		// find parent 
		Node* pre = nullptr;
		Node* temp = root;

		while(temp != current){	// find the current node

			if(temp -> data >= current -> data){	// current node is in the left subtree

				temp = temp -> left;
				
			}
			else{	// current node is in the right subtree

				pre = temp;
				temp  = temp -> right;

			}
			

		}
		return pre;

	}
	

}


int main(){

	Node* r_root = nullptr;

	Insert_recursive(10, r_root);
	Insert_recursive(5, r_root);
	Insert_recursive(15, r_root);
	Insert_recursive(4, r_root);
	Insert_recursive(6, r_root);
	Insert_recursive(7, r_root);
	Insert_recursive(14, r_root);
	Insert_recursive(20, r_root);
	Insert_recursive(19, r_root);
	Insert_recursive(25, r_root);

	int node = 10;

	Node* successor = Inorder_successor(r_root, node);

	std::cout << "The successor of "<< node << " is " << successor -> data << "\n";

	int data = 14;

	Node* predecessor = Predecessor(r_root, data);

	std::cout << "The predecessor of "<< data << " is " << predecessor -> data << "\n";
}
