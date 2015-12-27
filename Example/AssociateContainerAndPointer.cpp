#include <iostream>
#include <set>
#include <string>
#include <functional>
#include <algorithm>

void print(const std::string* ps)
{
	std::cout << *ps << std::endl;
}

void delFunc(const std::string* del)
{
	delete del;
	del = nullptr;
}

// �Լ����� ���ø�
struct DereferenceLess
{
	template <typename PtrT>
	bool operator()(PtrT pT1, PtrT pT2) const
	{
		return *pT1 < *pT2;
	}
};

int main(int argc, const char* argv[])
{
	std::set<std::string* > ssp;
	ssp.insert(new std::string("koko"));
	ssp.insert(new std::string("love"));
	ssp.insert(new std::string("elki"));
	ssp.insert(new std::string("momo"));

	// �ش� ������� ����ϸ� ���ϴ� ������ ������ �ʴ´�.
	// �׳� �Ѱ��ָ� ������ ������ �����ϰ� �ȴ�.
	std::for_each(ssp.begin(), ssp.end(), print);

	std::cout << std::endl;

	// Less �� �Լ��� Ÿ�� ����
	// �����Ͱ� ����Ű�� ������ ������ �� �ְԲ� �Ѵ�.
	struct StringPtrLess :
		public std::binary_function<const std::string*, const std::string*, bool>
	{
		bool operator()(const std::string* ps1, const std::string* ps2) const
		{
			return *ps1 < *ps2;
		}
	};

	typedef std::set<std::string*, StringPtrLess> StringPtrSet;
	StringPtrSet newSsp;

	newSsp.insert(new std::string("koko"));
	newSsp.insert(new std::string("love"));
	newSsp.insert(new std::string("elki"));
	newSsp.insert(new std::string("momo"));

	std::for_each(newSsp.begin(), newSsp.end(), print);

	std::cout << std::endl;

	// DereferenceLess �� �Լ��� ���ø� Ÿ�� ����
	typedef std::set<std::string*, DereferenceLess> DereferencePtrSet;
	DereferencePtrSet anotherNewSsp;

	anotherNewSsp.insert(new std::string("koko"));
	anotherNewSsp.insert(new std::string("love"));
	anotherNewSsp.insert(new std::string("elki"));
	anotherNewSsp.insert(new std::string("momo"));

	std::for_each(anotherNewSsp.begin(), anotherNewSsp.end(), print);

	std::for_each(ssp.begin(), ssp.end(), delFunc);
	std::for_each(newSsp.begin(), newSsp.end(), delFunc);
	std::for_each(anotherNewSsp.begin(), anotherNewSsp.end(), delFunc);

	return 0;
}
