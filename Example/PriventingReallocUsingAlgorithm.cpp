#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <string>

using namespace std;
 
int transmogrify(int x) { return x*x; }

template <class T>
void printVector(T SomeContainer, string str) {
	cout<<"=============="<<str<<"=============="<<endl;
	for each (int i  in SomeContainer) { cout<< i << endl; } 
	cout<<endl;
}

int main(int argc, const char* argv[])
{
    vector<int> values;

	for (int i = 0; i < 5; i++) {
		values.push_back(i);
	}

	vector<int> results1;

	// runtime error
	// transform(values.begin(), values.end(), results.end(), transmogrify);

	transform(values.begin(), values.end(), back_inserter(results1), transmogrify);
	// back_inserter
	// container supported push_back function. vector, string, deque, list and so on.
	
	printVector(results1, "results1");

	// if list then
	list<int> results2;
	transform(values.begin(), values.end(), front_inserter(results2), transmogrify);

	printVector(results2, "results2");

	// if front input
	list<int> results3;
	transform(values.rbegin(), values.rend(), front_inserter(results3), transmogrify);

	printVector(results3, "resulrs3");

	// if center input
	// use reserve
	results1.reserve(results1.size() + values.size());

	transform(values.begin(), values.end(), 
		inserter(results1, results1.begin() + (results1.size() / 2)), transmogrify);

	printVector(results1, "results1 center input");

	// overlap
	// use clear
	results1.clear();
	results1.reserve(values.size());

	transform(values.begin(), values.end(), back_inserter(results1), transmogrify);

	printVector(results1, "results1 overlap");	

    return 0;
}