// Leetcode problem 617. Merge to binary tree. 


#include <iostream>

// Definition of a binary tree node
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

void Merge(TreeNode* t1, TreeNode* t2, TreeNode*& t3);

class Solution {

//private:
//	TreeNode* root;

public:

	TreeNode* root;

	Solution(TreeNode* t = nullptr) : root{t}
	{}

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

	// my approach
	// return the new root node of the merged tree. 
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		
		if(t1 == nullptr){	// tree 1 is empty

			return t2;	
		}
		else if(t2 == nullptr){
			return t1;
		}
		else{	// neither three is empty
		
			TreeNode* new_tree = nullptr;
			Merge(t1, t2, new_tree);

			return new_tree;

		}
	}

	// reference solution
	TreeNode* mergeTrees_solution(TreeNode* t1, TreeNode* t2) {

		if(t1 == nullptr){

			return t2;
		}
		else if(t2 == nullptr){	// t1 != nullptr, inherit

			return t1;
			
		}
		else{
			t1 -> val += t2 -> val;
			
			t1 -> left = mergeTrees_solution(t1 -> left, t2 -> left);
			t1 -> right = mergeTrees_solution(t1 -> right, t2 -> right);

			return t1;
		}
	}
};

void Merge(TreeNode* t1, TreeNode* t2, TreeNode*& t3){

	if(t1 == nullptr && t2 == nullptr){	// Do not create new node

		return;
	}
	else if(t1 == nullptr){	// create new node based on t2
	
		t3 = new TreeNode{};

		t3 -> val = t2 -> val;

	}
	else if(t2 == nullptr){

		t3 = new TreeNode{};

		t3 -> val = t1 -> val;
		
	}
	else{

		t3 = new TreeNode{};

		t3 -> val = (t1 -> val + t2 -> val);

	}

	TreeNode* t1_new;
	TreeNode* t2_new;

	if(t1 == nullptr){
		t1_new = nullptr;
	}
	else{
		t1_new = t1 -> left;
	}

	if(t2 == nullptr){
		t2_new = nullptr;
	}
	else{
		t2_new = t2 -> left;
	}

	// go left
	Merge(t1_new, t2_new, t3 -> left);

	if(t1 != nullptr){

		t1_new = t1 -> right;
	}

	if(t2 != nullptr){

		t2_new = t2 -> right;
	}

	// go right	
	Merge(t1_new, t2_new, t3 -> right);

}


int main(){

	Solution t1{};

	t1.Insert(7, t1.root);
	t1.Insert(5, t1.root);
	t1.Insert(3, t1.root);
	t1.Insert(6, t1.root);
	t1.Insert(8, t1.root);
	t1.Insert(10, t1.root);

	t1.Print(t1.root);
	std::cout<< "\n";

	Solution t2{};

	t2.Insert(5, t2.root);
	t2.Insert(3, t2.root);
	t2.Insert(20, t2.root);
	t2.Insert(10, t2.root);
	t2.Insert(25, t2.root);
	t2.Insert(9, t2.root);
	t2.Insert(11, t2.root);
	t2.Insert(24, t2.root);

	t2.Print(t2.root);
	std::cout<< "\n";


	Solution t3{};
	t3.root = t3.mergeTrees(t1.root, t2.root);

	t3.Print(t3.root);
	std::cout<< "\n";

	t1.root = t1.mergeTrees_solution(t1.root, t2.root);

	t1.Print(t1.root);
	std::cout<< "\n";

}
