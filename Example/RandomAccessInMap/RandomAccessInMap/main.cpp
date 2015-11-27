#include <iostream>
#include <map>
#include <iterator>

typedef std::map<int, const char*> MYMAP;
typedef std::map<int, const char*>::const_iterator MYMAP_ITER;

int main(int argc, char* argv[])
{
	MYMAP myMap;

	// data push
	for (int i = 0; i<100; i++ )
	{
		myMap.insert(std::make_pair(i, "sampleData"));
	}

	std::cout<<"0 ~ 99 Data. One page contain 20 items. \nInput page = ";
	int page = 0;
	std::cin>>page;
	const int ONE_PAGE_COUNT = 20;

	// map nth ~ mth element 
	const int PRINT_START = (page-1)*ONE_PAGE_COUNT;
	const int PRINT_END = page*ONE_PAGE_COUNT;
	int check_index = 0;

	std::cout<<"=============================="<<std::endl;
	std::cout<<"Selected Item"<<std::endl;

	// data print
	for (auto it = myMap.begin(); it != myMap.end() && check_index < PRINT_END; ++it)
	{
		if (check_index++ < PRINT_START) continue;

		std::cout<<it->first<<" "<<it->second<<std::endl;
	}

	return 0;
}