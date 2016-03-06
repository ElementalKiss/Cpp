// TestProject.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MH_UTIL.h"

int main()
{
	using namespace MH_UTIL::STL;
	using namespace MH_UTIL::ETC;

	{
		some_line("Vector Test");
		vector<int> intVec;
		simple_init_push_back(intVec, 1, 2, 3, 4, 5);
		list<int> intList;
		simple_init_push_back(intList, 1, 2, 3, 4, 5);

		print_container_console(intVec, "vector init");
		erase_element(intVec, 2);
		print_container_console(intVec, "delete 2");

		print_container_console(intList, "list init");
		intList.remove(2);
		print_container_console(intList, "delete 2");

		vector<int> capacityCheckVec;
		capacityCheckVec.resize(100);
		capacityCheckVec.at(0) = 1;
		MH_UTIL::STL::erase_element(capacityCheckVec, 0);
		cout << "capacityCheckVec size = " <<capacityCheckVec.size() << endl;
		cout << "capacityCheckVec capacity = " << capacityCheckVec.capacity() << endl;
		shrink_vector(capacityCheckVec);
		cout << "execute shrink" << endl;
		cout << "capacityCheckVec capacity = " << capacityCheckVec.capacity() << endl;
	}

	{
		some_line("Array Size Test");
		// array_size Test
		int keyVals[] = { 1, 2, 3 };
		int mappedVals1[array_size(keyVals)];
		array<int, array_size(keyVals)> mappedVals2;

		cout << "mappedVals1 size = " << sizeof(mappedVals1) / sizeof(mappedVals1[0]) << endl;
		cout << "mappedVals2 size = " << mappedVals2.size() << endl;
	}



	return 0;
}

