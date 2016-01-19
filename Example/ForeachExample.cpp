#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char* argv[])
{
	const int VEC_SIZE = 5;

	std::vector<int> intArray;
	intArray.reserve(VEC_SIZE);
	intArray.push_back(10);
	intArray.push_back(20);
	intArray.push_back(30);
	intArray.push_back(40);
	intArray.push_back(50);

	// usin for each
	int sum = 0;
	for each (auto num in intArray)
	{
		sum += num;
	}

	std::cout << "total = " << sum << std::endl;
	
	// using lambda, for_each(algorithm)
	int sum2 = 0;
	std::for_each(intArray.begin(), intArray.end(), [&sum2](int &num) {sum2 += num; });
	
	std::cout << "total2 = " << sum2 << std::endl;
}