#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

template <class T>
void print_container(T& SomeContainer, string str) {
	cout << "==============" << str << "==============" << endl;
	cout << "[INFO] Container size = " << SomeContainer.size() << endl;
	long long count = 1;
	for each (auto i  in SomeContainer) { cout << count++ << "th value = " << i << endl; }
	cout << endl;
}

int main(int argc, const char* argv[])
{
	vector<int> intVec;
	const int VEC_SIZE = 10;
	intVec.reserve(VEC_SIZE);

	for (int i = 0; i < VEC_SIZE; i++) {
		intVec.push_back(i / 2);
	}

	print_container(intVec, "init vector");

	remove(intVec.begin(), intVec.end(), 3);

	print_container(intVec, "delete 3");

	// 7th ~ 10th value = 4.
	// size is 10.

	intVec.erase(remove(intVec.begin(), intVec.end(), 2), intVec.end());

	print_container(intVec, "real delete 2");

	list<int> intList;
	const int LIST_SIZE = 10;

	for (int i = 0; i < LIST_SIZE; i++) {
		intList.push_back(i / 2);
	}

	print_container(intList, "init list");

	intList.remove(3);

	print_container(intList, "delete 3");

	return 0;
}