// Leetcode 581
// Two solutions. 
// 1. Copy and sort + compare with original. (Provided by the leetcode)
// 2. Brute search: https://www.youtube.com/watch?v=UfBfr-VRYOU&feature=youtu.be

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

// Brute force solution. 
// Time: O(n), space: O(1)
int findUnsortedSubarray_brute(std::vector<int>& nums) {

	int length = nums.size();

	if(length == 1){
		return 0;
	}

	int s{};
	int e{};

	int max{};
	int min{};

	bool pass = false;


	for(int i = 0; i < length - 1; ++i){

		if(nums[i] > nums[i + 1]){

			s = i;
			break;
		}

	}
	
	for(int j = (length - 1); j > 0; --j){

		if( nums[j] < nums[j - 1]){	// violates

			e = j;
			break;
		}

	}

	if(s == 0 && e == 0){	// already sorted

		return 0;
	}

	// sort between [s, e]
	// get the iterator
	std::vector<int>::iterator it_s = (nums.begin() + s);
	std::vector<int>::iterator it_e = (nums.end() - (length - 1 - e));
	std::sort(it_s, it_e);

	min = nums[s];	// minimum value of the sorted subarray. 
	max = nums[e];

	while(!pass){

		pass = true;
		for(int i = 0; i < s; ++i){


			if(nums[i] > min){

				s = i;

				pass = false;

				break;
			}
		}

		for(int j = length - 1; j > e; --j){

			if(nums[j] < max){

				e = j;
				pass = false;
				break;
			}

		}

		if(pass) break;

		// sort again
		std::vector<int>::iterator it_s = (nums.begin() + s);
		std::vector<int>::iterator it_e = (nums.end() - (length - 1 - e));
		std::sort(it_s, it_e);
	
		min = nums[s];	// minimum value of the sorted subarray. 
		max = nums[e];
	}

	return (e - s + 1);

}

int main(){

	std::vector<int> my_vector {2, 2, 3, 8, 7, 2, 1};

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
//	int adjust2 = findUnsortedSubarray_solution(my_vector); 
//
//	std::cout << "Subarray length = " << adjust2 << "\n";

	int d3 = findUnsortedSubarray_brute(my_vector);

	std::cout << "Subarray length = " << d3 << "\n";

	for(auto& v : my_vector){

		std::cout<< v << " ";
	}
	std::cout<< "\n";
}
