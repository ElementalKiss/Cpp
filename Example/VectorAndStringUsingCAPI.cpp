#include <iostream>
#include <string>
#include <vector>

// simple print C functions.
void doSomthingVector(int* pInts, size_t numverInts) 
{ 
	for (int i = 0; i < numverInts; i++)
	{
		std::cout<<"print number = "<<pInts[i]<<std::endl;
	}
	return; 
}

void dosomthingString(const char* pString)
{
	std::cout<<"print pString[0] = "<<pString[0]<<std::endl;
}

// fill data C function
size_t fillArrayDouble(double* pArray, size_t arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		pArray[i] = i;
	}

	return arraySize;
}

size_t fillString(char* pArray, size_t arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		pArray[i] = 'a' + i;
	}
	
	return arraySize;
}

int main(int argc, const char* argv[])
{
	// vector example
	std::vector<int> intVec;

	const int vecReserveSize = 5;
	intVec.reserve(vecReserveSize);

	for (int i = 0; i < 4; i++)
	{
		intVec.push_back(i);
	}

	doSomthingVector(&intVec[0], intVec.size());

	// error C2664: 'doSomthingVector' : cannot convert parameter 1 from 'std::_Vector_iterator<_Myvec>' to 'const int *'
	// doSomthingVector(intVec.begin(), intVec.size());
	
	// string example
	std::string myString;
	myString = "love koko";

	dosomthingString(myString.c_str());

	// fill double vector
	const int maxNumDoubles = 10;

	std::vector<double> vd(maxNumDoubles);
	vd.resize(fillArrayDouble(&vd[0], 5));

	for (auto it = vd.begin(); it != vd.end(); ++it)
	{
		std::cout<<"print double = "<<*it<<std::endl;
	}

	// fill string
	const int maxNumChar = 255;

	std::vector<char> vc(maxNumChar);
	size_t charsWritten = fillString(&vc[0], 10);

	std::string newStr(vc.begin(), vc.begin()+charsWritten);

	std::cout<<"newStr = "<<newStr<<std::endl;

	return 0;
}