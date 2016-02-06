#include <iostream>
#include "Employee.h"
using namespace std;

int main(int argc, const char* argv[])
{
	EmplDSet se;

	Employee e1(1, "koko");
	Employee e2(2, "momo");
	Employee e3(3, "popura");

	se.insert(e1);
	se.insert(e2);
	se.insert(e3);

	// Method1 : using const_cast
	EmplDSet::iterator it = se.find(1 /* 1 call conversion constructor : Employee temp(1) */);

	if (it != se.end()) {
		// Error
		// it->SetTitle("Power Boss");
		// error C2662: 'Employee::SetTitle' : 
		// cannot convert 'this' pointer from 'const Employee' to 'Employee &'
		// Conversion loses qualifiers

		// Using const cast
		const_cast<Employee&>(*it).SetTitle("Boss");
		it->PrintInfo();
	}

	// Method2 : using Copy constructor and erase
	Employee selectedID(2);
	
	EmplDSet::iterator newIt = se.find(selectedID); // 1.find
	if (newIt != se.end()) {
		Employee e(*newIt); // 2.copy

		// avoiding iterator invalidation i++
		se.erase(newIt++); // 3.erase

		// 4.edit
		e.SetName("Power Momo");
		e.SetTitle("New Boss");

		se.insert(e); // 5.insert
		(se.find(2))->PrintInfo();
	}

	return 0;
}