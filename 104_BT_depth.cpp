// Leetcode 104

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

int maxDepth(TreeNode* root) {

	if(root == nullptr){

		return 0;

	}
	else if(root -> left == nullptr && root -> right == nullptr){

		return 1;

	}
	else{

		int left = maxDepth(root -> left);

		int right = maxDepth(root -> right);

		int max = std::max(left, right);

		return (max + 1);

	}

        
}

int main(){

	TreeNode* root = nullptr;

	Insert(10, root);
	Insert(5, root);
	Insert(12, root);
	Insert(3, root);
	Insert(9, root);
	Insert(8, root);
	Insert(11, root);

	
	int d = maxDepth(root);

	std::cout<< "Depth = " << d << "\n";

}
