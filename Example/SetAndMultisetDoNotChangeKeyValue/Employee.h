#pragma once
#include <set>
#include <string>
#include <functional>
#include <iostream>

using namespace std;

class Employee
{
public:
	Employee(void);
	~Employee(void);

	// Conversion Constructor
	Employee(const int id);

	Employee(const int id, string name);

	// Copy Constructor
	Employee(const Employee& emp);


	// Getter and Setter
	inline const int GetId() const { return m_id; }
	inline void SetId(const int id) { m_id = id; }

	inline const string& GetName() const { return m_name; }
	inline void SetName(const string& name) { m_name = name; }

	inline const string& GetTitle() const { return m_title; }
	inline void SetTitle(const string& title) { m_title = title; }


	// Method
	void PrintInfo() const { 
		cout<<"Selected Employee = Id : "<<GetId()<<", name : "<<GetName()<<", title : "<<GetTitle()<<endl;; 
	}

private:
	// Member Variable
	int m_id;
	string m_name;
	string m_title;
};

// Less Function
struct IDNumberLess: public binary_function<Employee, Employee, bool> 
{
	bool operator() (const Employee& lhs, const Employee& rhs) const
	{
		return lhs.GetId() < rhs.GetId();
	}
};

typedef set<Employee, IDNumberLess> EmplDSet;