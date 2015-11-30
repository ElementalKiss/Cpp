#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
	const int ARRSIZE = 10;

	int testArr[ARRSIZE] = { 1,2,3,4,5,6,7 };

	// functor simple example
	{
		struct Product {
			int sum;

			Product() : sum(0) {}

			void operator()(int e)
			{
				sum += e;
			}

			int getSum() const { return sum; }
		};

		Product someResult;

		// using functor
		someResult = std::for_each(testArr, testArr + ARRSIZE, Product());

		std::cout << "using functor = " << someResult.getSum() << std::endl;
	}

	// simple lambda
	{
		// using lambda
		int lambdaResult = 0;

		std::for_each(testArr, testArr + ARRSIZE, [&](int e) {lambdaResult += e; });

		std::cout << "using lambda = " << lambdaResult << std::endl;
	}

	return 0;
}