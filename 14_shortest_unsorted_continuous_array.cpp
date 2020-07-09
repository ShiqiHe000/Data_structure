#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void Get_min(std::vector<int>& nums, std::queue<int>& Min_index, int i, int length);
int findUnsortedSubarray(std::vector<int>& nums); 

void Get_min(std::vector<int>& nums, std::queue<int>& Min_index, int i, int length){

	// put the first value in the queue
	int min_v = nums[i];
	Min_index.push(i);

	for(int j = (i + 1); j < length; ++j){

		if(nums[j] < min_v){

			min_v = nums[j];

			// clear the queque	
			Min_index = std::queue<int>();		

			Min_index.push(j);
		}
		else if(nums[j] == min_v){

			Min_index.push(j);
		}

	}

}


int findUnsortedSubarray(std::vector<int>& nums) {

	int length = nums.size();

	if(length == 1){

		return 0;
	}

	int i{};
	int e{};
	int s = length;

	std::queue<int> Min_index;

	while(i <= (length - 1)){

		Get_min(nums, Min_index, i, length);

		while(!Min_index.empty()){

			if(i == (Min_index.front())){	// right position

				Min_index.pop();
				++i;
			}
			else{	// swap

				int temp = nums[i];
				nums[i] = nums[Min_index.front()];
				nums[Min_index.front()] = temp;

				s = std::min(i, s);
				e = std::max(Min_index.front(), e);

				Min_index.pop();

				++i;
			}
		}	


	}

	int num = (e - s + 1);
	
	if(num < 0){

		return 0;
	}
	else{

		return num;
	}
        
}

// reference solution. First copy the vector, then use the std::sort()
// operation offered by c++. The number between the first and the last 
// different elements between the two vectors should be returned. 
int findUnsortedSubarray_solution(std::vector<int>& nums) {

	std::vector<int> copy{};

	copy = nums;	// copy opperator

	std::sort(nums.begin(), nums.end());	// sort the vector

	int length = copy.size();

	int s = length;
	int e{};

	for(int i = 0; i < length; ++i){

		if(nums[i] != copy[i]){
			s = i;
			break;
		}

	}

	for(int j = (length - 1); j >= 0; --j){

		if(nums[j] != copy[j]){

			e = j;
			break;
		}
	}

	int num = (e - s + 1);
	
	if(num < 0){

		return 0;
	}
	else{

		return num;
	}
}

int main(){

	std::vector<int> my_vector {1, 2, 3, 2, 5, 9};

//	int adjust = findUnsortedSubarray(my_vector); 
//
//	std::cout << "Subarray length = " << adjust << "\n";
//
//	for(auto& v : my_vector){
//
//		std::cout<< v << " ";
//	}
//	std::cout<< "\n";
//
	int adjust2 = findUnsortedSubarray_solution(my_vector); 

	std::cout << "Subarray length = " << adjust2 << "\n";

	for(auto& v : my_vector){

		std::cout<< v << " ";
	}
	std::cout<< "\n";
}
