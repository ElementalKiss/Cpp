#include "Employee.h"

Employee::Employee(void) : m_id(0), m_name("noname"), m_title("notitle")
{
}

Employee::~Employee(void)
{
}

Employee::Employee(const int id) : m_id(id), m_name("noname"), m_title("notitle")
{
}

Employee::Employee(const int id, string name) : m_id(id), m_name(name), m_title("notitle")
{
}

Employee::Employee(const Employee& emp) : m_id(emp.m_id), m_name(emp.m_name), m_title(emp.m_title)
{
}