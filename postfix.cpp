// input a string of postfix expression, output the result. 
// Assume the expression is correct. 

// The delimiters inside an expression can only be "," or " ". 
// The operands can only be integers. 

#include <iostream>
#include <stack>
#include <string>

int Postfix(std::string& e);
bool Delimiter(char c);
bool Number(char c);
bool Operator(char c);
int Compute(int a, int b, char c);


int main(){

	std::cout<< "Enter a postfix expression: \n";
	std::string expression{};
	std::getline(std::cin, expression);

	int r = Postfix(expression);

	std::cout<< "Result = " << r << "\n";

}

int Postfix(std::string& e){

	int length = e.length();

	if(length == 0) return 0;	// if empty

	std::stack<int> Stack{};	// stack to preforms the computations. 

	for(int i = 0; i < length; ++i){
		
		if(Delimiter(e[i])) continue;

		if(Number(e[i])){ 	// if its a number

			int operand{};

			while(i < length && Number(e[i])){	// read the whole number
				
				operand = operand * 10 + (e[i] - '0');

				++i;
			}

			// push in stack
			Stack.push(operand);
			--i;
		
		}
		else if(Operator(e[i])){	// if its an operator

			int o2 = Stack.top();
			Stack.pop();

			int o1 = Stack.top();
			Stack.pop();

			int o_new = Compute(o1, o2, e[i]);

			Stack.push(o_new);
		}
	}

	return (Stack.top());

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


// check if the operand is a number
bool Number(char c){

	if(c >= '0' && c <= '9'){
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

// compute the expression
int Compute(int a, int b, char c){

	if(c == '+'){

		return (a + b);
	}
	else if(c == '-'){

		return (a - b);
	}
	else if(c == '*'){

		return (a * b);
	}
	else{

		return (a / b);
	}
}
