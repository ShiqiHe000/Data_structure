// Leetcode 543

// Diameter = largest edge number between two nodes in the BT tree. 

#include <iostream>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void Print(TreeNode* r){

	if(r == nullptr){
		return;
	}
	else{

		Print(r -> left);

		std::cout << r -> val << " ";

		Print(r -> right);

	}
}

void Insert(int v, TreeNode*& r){

	if(r == nullptr){

		r = new TreeNode{};

		r -> val = v;
	}
	else{
		if(v <= r -> val){	// go left

			Insert(v, r -> left);
		}
		else{	
			Insert(v, r -> right);	// go right

		}
	}

}


// return the node number. If you want the edge number, you should subtract the value by 1. 
int Depth(TreeNode* node){

	if(node == nullptr){

		return 0;
	}
	else{

		if(node -> left == nullptr && node -> right == nullptr){

			return 1;	// one node
		}
		else{

			// go left
			int left = Depth(node -> left);
		
			// go right 
			int right = Depth(node -> right);

			int max = std::max(left, right);

			return (max + 1);	// add the root node

		}

	}
}


int diameterOfBinaryTree(TreeNode* root) {

	if(root == nullptr){

		return 0;
	}
       
	int max{};

	TreeNode* temp = root;
 
	while(temp != nullptr){

		int left = Depth(temp -> left);	
		int right = Depth(temp -> right);	
//std::cout<< "left = " << left << " right " << right << "\n";
		max = std::max(max, left + right + 1);	// add one root node

		if(left > right){

			temp = temp -> left;
		}
		else{

			temp = temp -> right;
		}

	}

	return (max - 1);
}

int main(){

	TreeNode* root = nullptr;

	Insert(10, root);
	Insert(5, root);
	Insert(12, root);
	Insert(3, root);
	Insert(2, root);
	Insert(6, root);
	Insert(7, root);
	Insert(8, root);
	Insert(1, root);

	Print(root);
	std::cout<< "\n";

	int d = diameterOfBinaryTree(root);

	std::cout<< "diameter = " << d << "\n";
}

