// TestProject.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MH_UTIL.h"

int main()
{
	using namespace MH_UTIL::STL;
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


	test();

	return 0;
}

