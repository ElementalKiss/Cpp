#include <iostream>
#include <vector>
#include <string>

void printSizeAndCapacity(const std::vector<int>& vec)
{
	std::cout<<"size = "<<vec.size()<<std::endl;
	std::cout<<"capacity = "<<vec.capacity()<<std::endl<<std::endl;

}

int main(int argc, const char* argv[])
{
	const int maxNumContestant = 100000;
	std::vector<int> contestant;
	contestant.reserve(maxNumContestant);
	
	// 0, 100000
	printSizeAndCapacity(contestant);

	// add 100000 contestant
	for (int i = 0; i < maxNumContestant; i++)
	{
		contestant.push_back(i);
	}

	printSizeAndCapacity(contestant);

	// erase 99990 contestant
	contestant.erase(contestant.begin() + 10, contestant.end());

	printSizeAndCapacity(contestant);

	// swap skill
	std::vector<int>(contestant).swap(contestant);

	printSizeAndCapacity(contestant);
	return 0;
}