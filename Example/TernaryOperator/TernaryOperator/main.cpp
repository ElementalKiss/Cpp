#include <iostream>

struct SomeClass 
{ 
	char* str; 
};

SomeClass* somthingReturn() { return nullptr; }

int main(int argc, char* argv[])
{
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
	myStruct ? str_ptr = myStruct->str : str_ptr = "";

	return 0;
}