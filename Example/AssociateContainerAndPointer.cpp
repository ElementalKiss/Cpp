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

// 함수자의 템플릿
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

	// 해당 방법으로 출력하며 원하는 순서가 나오지 않는다.
	// 그냥 넘겨주면 포인터 값으로 정렬하게 된다.
	std::for_each(ssp.begin(), ssp.end(), print);

	std::cout << std::endl;

	// Less 비교 함수자 타입 정의
	// 포인터가 가리키는 값으로 정렬할 수 있게끔 한다.
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

	// DereferenceLess 비교 함수자 템플릿 타입 정의
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
