#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int>& vec) 
{
	static int count = 0;
	cout << "-----" << endl;
	cout << count++ << "th" << endl;

	for (int num : vec) {
		cout << num << endl;
	}
	cout << "-----" << endl;
}

int main(int argc, const char* argv[])
{
	vector<int> intVec;
	const int VECSIZE = 10;
	intVec.reserve(VECSIZE);

	for (size_t i = 0; i < 5; i++) {
		intVec.push_back(i);
	}

	vector<int>::reverse_iterator ri = find(intVec.rbegin(), intVec.rend(), 3);

	if (intVec.size() <= VECSIZE) {
		intVec.insert(ri.base(), 99);
	}
	// 0,1,2,3,99,4
	printVec(intVec);

	// intVec.erase(ri.base());

	// 0,1,2,3,4 -> delete 99!!
	// printVec(intVec);

	// not always complie.
	// intVec.erase(--ri.base());

	// printVec(intVec);

	// always.
	intVec.erase((++ri).base());

	printVec(intVec);
}