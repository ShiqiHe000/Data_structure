// Transfer infix expression into postfix expression

// The operands inside the expression can be numbers or characters

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

bool Delimiter(char c);
bool Operator(char c);
void Infix_to_postfix(std::string& e, std::vector<char>& p_string);
bool Top_higher_or_equal(char top, char c);

int main(){

	std::cout<< "Enter infix expression: \n";

	std::string expression{};

	std::getline(std::cin, expression);

	std::vector<char> p_string{};
	Infix_to_postfix(expression, p_string);

	for(auto& v : p_string){

		std::cout<< v << " ";
	}
	std::cout<< "\n";

}

// Transfer infix to postfix. 
void Infix_to_postfix(std::string& e, std::vector<char>& p_string){

	int length = e.length();

	if(length == 0){	// if empty string

		return;
	}

	std::stack<char> operation{}; 	// stack for operations
	
	for(int i = 0; i < length; ++i){
		if(Delimiter(e[i])) continue;
	

		if(e[i] == ')'){	// if ')'
			
			// read the stack until we reach '('
			while(operation.top() != '('){

				p_string.emplace_back(operation.top());

				operation.pop();
			}
		
			operation.pop();

		}
		else if(e[i] == '('){	// left parenthese push on top of the stack. 
			operation.push(e[i]);	
		}
		else if(Operator(e[i])){	// math operations

			if(operation.empty()){	// if empty stack
				operation.push(e[i]);	// push to stack
			}
			else if(Top_higher_or_equal(operation.top(), e[i])){	// top operation has higher priority
				// append
				while(Top_higher_or_equal(operation.top(), e[i])){
					
					p_string.emplace_back(operation.top());
					operation.pop();
					if(operation.empty()) break;
				}
				operation.push(e[i]);	// put this operation into stack
			}
			else{	// new operation has higher priority
				// put in stack
				operation.push(e[i]);
			}

		}
		else{	// operand

			// append to the p_string
			p_string.emplace_back(e[i]);
		}
	
	}

	while(!operation.empty()){	// still something in stack, append to the end 

		p_string.emplace_back(operation.top());

		operation.pop();
	}




}

// check if the character is a delimiter. 
bool Delimiter(char c){

	if(c == ' ' || c == ','){
		return true;
	}
	else{
		return false;
	}
} 


// check if the operand is an operator
bool Operator(char c){

	if(c == '+' || c == '-' || c == '*' || c == '/'){

		return true;
	}
	else{
		return false;
	}
}

// Top operator in the stack has higher or equal priority than the current operator c. 
bool Top_higher_or_equal(char top, char c){

	static std::unordered_map<char, int> scores = {
							{'+', 1},
							{'-', 1},
							{'*', 2},
							{'/', 2}
							};
	int top_s = scores[top];
	int c_s = scores[c];

	if(top_s >= c_s){

		return true;
	}
	else{
		return false;
	}
}

