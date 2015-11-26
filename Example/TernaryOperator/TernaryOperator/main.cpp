#include <iostream>

struct SomeClass 
{ 
	char* str; 
};

SomeClass* somthingReturn() { return nullptr; }

void someFunction(int num1, int num2) { return; }

int main(int argc, char* argv[])
{
	//// simple example
	// char pointer
	char* str_ptr = nullptr;

	// class pointer
	SomeClass* myStruct = somthingReturn();

	// if - else
	if (myStruct != nullptr)
	{
		str_ptr = myStruct->str;
	}
	else
	{
		str_ptr = "";
	}
	
	// ternary operator
	myStruct != nullptr ? str_ptr = myStruct->str : str_ptr = "";


	//// readblity?
	int testNum1 = 0;
	int testNum2 = 0;

	// if - else
	int max = 0;
	if (testNum1 > testNum2 )
	{
		max = testNum1;
	}
	else
	{
		max = testNum2;
	}

	int sum = testNum1 + testNum2;
	
	someFunction(max, sum);

	// ternary operator
	someFunction(testNum1 > testNum2 ? testNum1 : testNum2, testNum1 + testNum2);

	return 0;
}